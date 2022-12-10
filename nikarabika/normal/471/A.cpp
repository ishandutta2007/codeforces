#include <iostream>

using namespace std;

int a[10];

int main()
{
    for(int i=0; i<6; i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    bool is = false;
    for(int i=1; i<10; i++)
    {
        if(a[i]>=4)
        {
            is=true;
            a[i]-=4;
            break;
        }
    }
    if(!is)
    {
        cout<<"Alien"<<endl;
        return 0;
    }
    is = false;
    for(int i=1; i<10; i++)
    {
        if(a[i]==2)
        {
            cout<<"Elephant"<<endl;
            return 0;
        }
        if(a[i]==1)
        {
            cout<<"Bear"<<endl;
            return 0;
        }
    }
    return 0;
}