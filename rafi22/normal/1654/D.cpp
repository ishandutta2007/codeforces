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

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

struct edge
{
    int u,p,q;
};

vector<edge>G[200007];
vector<pair<int,int>>fac[200007];
bool sieve[200007];
int ile[200007];
int R,ans;

void dfs(int v,int o)
{
    for(auto e:G[v])
    {
        if(e.u==o) continue;
        for(auto c:fac[e.p])
        {
            int z=max(0LL,c.nd-ile[c.st]);
            R=R*pot(c.st,z)%mod;
            ile[c.st]+=z;
        }
        for(auto c:fac[e.p]) ile[c.st]-=c.nd;
        for(auto c:fac[e.q]) ile[c.st]+=c.nd;
        dfs(e.u,v);
        for(auto c:fac[e.p]) ile[c.st]+=c.nd;
        for(auto c:fac[e.q]) ile[c.st]-=c.nd;
    }
}

void dfs1(int v,int o,int x)
{
    ans=(ans+x)%mod;
    for(auto e:G[v])
    {
        if(e.u==o) continue;
        dfs1(e.u,v,x*e.q%mod*pot(e.p,mod-2)%mod);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=200000;i++)
    {
        if(sieve[i]) continue;
        fac[i].pb({i,1});
        for(int j=2*i;j<=200000;j+=i)
        {
            sieve[j]=1;
            int x=j,c=0;
            while(x%i==0)
            {
                x/=i;
                c++;
            }
            fac[j].pb({i,c});
        }
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        mod=mod1;
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int a,b,p,q;
            cin>>a>>b>>p>>q;
            int g=__gcd(p,q);
            p/=g;
            q/=g;
            G[a].pb({b,p,q});
            G[b].pb({a,q,p});
        }
        R=1;
        dfs(1,0);
        ans=0;
        dfs1(1,0,R);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            ile[i]=0;
            G[i].clear();
        }
    }

    return 0;
}