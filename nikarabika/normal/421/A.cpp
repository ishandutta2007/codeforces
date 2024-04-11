#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin>>n;
    cin>>a>>b;
    bool R[n];
    for(int i=0; i<n; i++)
        R[i]=true;
    for(int i=0; i<a; i++)
    {
        int t;
        cin>>t;
        R[t-1]=false;
    }
    for(int i=0; i<b; i++)
    {
        int t;
        cin>>t;
    }
    for(int i=0; i<n; i++)
    {
        if(R[i])
            cout<<2;
        else
            cout<<1;
        cout<<' ';
    }
    return 0;
}