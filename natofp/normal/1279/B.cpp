#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n,s; cin>>n>>s;
    vector<ll> a;
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x; a.push_back(x);
    }
    ll ile=0;
    ll rest=s;
    for(int i=0;i<n;i++)
    {
        if(rest>=a[i])
        {
            rest-=a[i];
            ile++;
        }
        else break;
    }
    if(ile==n)
    {
        cout<<0<<"\n";
        return;
    }
    int idi=-1;
    int maxi=-1;
    for(int i=0;i<ile;i++)
    {
        if(a[i]>maxi)
        {
            idi=i;
            maxi=a[i];
        }
    }
    if(rest>0)
    {
        if(a[ile]>maxi)
        {
            maxi=a[ile];
            idi=ile;
        }
    }
    ll ile2=0;
    ll zost=s;
    for(int i=0;i<n;i++)
    {
        if(i==idi) continue;
        if(zost>=a[i])
        {
            zost-=a[i];
            ile2++;
        }
        else break;
    }
    if(ile>=ile2) cout<<0<<"\n";
    else cout<<idi+1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}