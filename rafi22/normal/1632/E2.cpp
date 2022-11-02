#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

vector<int>G[300007];
int d[300007];
int h[300007];
int o[300007];
bool is[300007];
int c[300007];
int pref[300007];
int suf[300007];

void dfs(int v)
{
    h[v]=0;
    for(auto u:G[v])
    {
        if(u==o[v]) continue;
        d[u]=d[v]+1;
        o[u]=v;
        dfs(u);
        h[v]=max(h[v],h[u]+1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,a,b;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            G[i].clear();
            is[i]=0;
            c[i]=0;
            suf[i]=-inf;
            pref[i]=-inf;
        }
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1);
        int mx=-1,p;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>mx)
            {
                p=i;
                mx=d[i];
            }
        }
        vector<int>P;
        while(p)
        {
            P.pb(p);
            is[p]=1;
            p=o[p];
        }
        reverse(all(P));
        for(int i=0;i<sz(P);i++)
        {
            int v=P[i];
            for(auto u:G[v])
            {
                if(!is[u]) c[i]=max(h[u]+1,c[i]);
            }
        }
        for(int i=0;i<sz(P);i++)
        {
            if(i) pref[i]=pref[i-1];
            pref[i]=max(pref[i],i+c[i]);
        }
        for(int i=sz(P)-1;i>=0;i--)
        {
            suf[i]=-inf;
            if(i!=sz(P)-1) suf[i]=suf[i+1];
            suf[i]=max(suf[i],c[i]-i);
        }
        int j=0;
        for(int x=1;x<=n;x++)
        {
            int ans=inf;
            for(;j<sz(P);j++)
            {
                int l=(j+x)/2;
                int act=max({sz(P)-1-j+x,pref[l],j+x+suf[l+1]});
                if(act>=ans)
                {
                    j--;
                    break;
                }
                ans=act;
            }
            cout<<min(ans,mx)<<" ";
        }
        cout<<endl;
        for(int i=0;i<=n;i++)
        {
            suf[i]=-inf;
            pref[i]=-inf;
        }
    }

    return 0;
}