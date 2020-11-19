//To know the concept of vtable.
using namespace std;

#include<iostream>

class  Base
{
    public:
    int a,b;
        virtual void fun()
        {
            cout<<"Base Fun\n";
        }
        virtual void gun()
        {
            cout<<"Base Gun\n";
        }
        void sun()
        {
            cout<<"Base Sun\n";
        }
};

class Derived:public Base
{
    public:
       int x,y; 
        void fun()
        {
            cout<<"Derived Fun\n";
        }
        void run()
        {
            cout<<"Derived run\n";
        }
        virtual void sun()
        {
            cout<<"Derived Sun\n";
        }
};

int main()
{
    Base boj;
    Derived dobj;
    int *op=(int*)&dobj;
    int *vtable=(int *)*op;
    void (*fp)();
    fp=(void (*)())*vtable;
    fp();

    fp=(void (*)())*(vtable+1);
    fp();
    fp=(void (*)())*(vtable+2);
    fp();
    fp=(void (*)())*(vtable+0);
    fp();
    return 0;
}
