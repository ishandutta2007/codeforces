#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c; cin>>r>>c;
    if(r==1 && c==1)
    {
        cout<<0; return 0;
    }
    if(r==1)
    {
        for(int i=1;i<=c;i++) cout<<i+1<<" ";
        return 0;
    }
    if(c==1)
    {
        for(int i=1;i<=r;i++) cout<<i+1<<endl;
        return 0;
    }
    for(int i=1;i<=c;i++) cout<<i+1<<" ";
    cout<<endl;
    for(int i=2;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<(c+i)*(j+1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}