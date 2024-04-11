#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
const int nax=1e6+5;
vector<int> adj[nax];
ll cc[nax];

const int mod=998244353;

ll pot(ll a,ll b)
{
    if(b==0) return 1;
    ll res=pot(a,b/2);
    res%=mod;
    res*=res;
    res%=mod;
    if(b%2==1) res*=a;
    res%=mod;
    return res;
}

ll odw(ll a)
{
    return pot(a,mod-2);
}

ll ans=0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ile; cin>>ile;
        for(int j=1;j<=ile;j++)
        {
            int x; cin>>x;
            adj[i].push_back(x);
            cc[x]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int akt=adj[i][j];
            ll prob=odw(n);
            ll roz=adj[i].size();
            prob*=odw(roz);
            prob%=mod;
            prob*=cc[adj[i][j]];
            prob%=mod;
            prob*=odw(n);
            prob%=mod;
            ans+=prob;
            ans%=mod;
        }
    }
    cout<<ans;
    return 0;
}