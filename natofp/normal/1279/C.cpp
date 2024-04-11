#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e5+5;
ll pos[nax];

void solve()
{
    ll n,m; cin>>n>>m;
    vector<ll> a;
    vector<ll> b;
    ll maxi=0;
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x; a.push_back(x);
        pos[x]=i;
    }
    for(int i=1;i<=m;i++)
    {
        ll x; cin>>x; b.push_back(x);
    }
    ll res=0;
    for(int i=1;i<=m;i++)
    {
        ll akt=b[i-1];
        ll wys=pos[akt];
        if(wys<=maxi) res++;
        else
        {
            ll zost=wys-1-(i-1);
            res+=2*zost+1;
            maxi=wys;
        }
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}