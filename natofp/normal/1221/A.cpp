#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        ll sum=0;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            ll x; cin>>x;
            if(x<=2048)
            {
                sum+=x;
            }
        }
        if(sum>=2048) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}