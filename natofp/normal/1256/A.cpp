#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        ll a,b,n,s; cin>>a>>b>>n>>s;
        if(a*n+b<s)
        {
            cout<<"NO"<<endl; continue;
        }
        s%=n;
        if(b>=s) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        continue;

    }
    return 0;
}