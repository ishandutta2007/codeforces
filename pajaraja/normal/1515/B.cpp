#include <bits/stdc++.h>
using namespace std;
map<int,bool> db;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i*i<=500000000;i++) db[2*i*i]=true;
    for(int i=1;i*i<=250000000;i++) db[4*i*i]=true;
    while(t--)
    {
        int n;
        cin>>n;
        if(db[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}