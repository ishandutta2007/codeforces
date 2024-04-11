#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e6+5;

int xd[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        ll n,k; cin>>n>>k;
        string s; cin>>s;
        vector<int> a;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0') a.push_back(i+1);
        }
        for(int i=0;i<a.size();i++)
        {
            int ile=min(k,(ll)a[i]-i-1);
            k-=ile;
            a[i]-=ile;
        }
        for(int i=1;i<=n;i++) xd[i]=0;
        for(int i=0;i<a.size();i++) xd[a[i]]=1;
        for(int i=1;i<=n;i++)
        {
            if(xd[i]==0) cout<<1;
            else cout<<0;
        }
        cout<<"\n";

    }
    return 0;
}