#include <iostream>

using namespace std;

char T[200];

int main()
{
    cin>>T;
    bool x=false;

    int s=0;
    for(int i=0; i<200; i++)
        if(T[i])
            s++;
        else
            break;
    int y=s-2;
    for(int i=0; i<s; i++)
    {
        if(T[i]==0)
            break;
        if(T[i]=='W' && T[i+1]=='U' && T[i+2]=='B')
        {
            cout<<' ';
            i+=2;
        }
        else
        {
            cout<<T[i];
        }


    }
    cout<<endl;
    return 0;
}