#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

//#define int long long
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

const bool multi=0;

const int N=500007;

vector<pair<int,int>>G[N];
int o[N],kr[N];
bool take[N];
int d[N];

int r[N],s[N];

void dfs(int v,int x)
{
    r[v]=x;
    for(auto u:G[v])
    {
        if(u.st==o[v]) continue;
        o[u.st]=v;
        d[u.st]=d[v]+1;
        kr[u.st]=u.nd;
        dfs(u.st,x);
    }
}

void Union(int a,int b,int c)
{
    if(s[r[a]]>s[r[b]]) swap(a,b);
    s[r[b]]+=s[r[a]];
    G[a].pb({b,c});
    G[b].pb({a,c});
    o[a]=b;
    kr[a]=c;
    d[a]=d[b]+1;
    dfs(a,r[b]);
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
        int n,k,m,a,b,w;
        cin>>n>>k>>m;
        for(int i=1;i<=n;i++)
        {
            r[i]=i;
            s[i]=1;
        }
        for(int i=1;i<=k;i++)
        {
            cin>>a>>b;
            Union(a,b,i);
        }
        take[0]=1;
        ll ans=0;
        while(m--)
        {
            cin>>a>>b>>w;
            if(r[a]==r[b])
            {
                vector<int>V;
                while(a!=b)
                {
                    if(d[a]<d[b]) swap(a,b);
                    V.pb(a);
                    if(!take[kr[a]]) ans+=(ll)w;
                    take[kr[a]]=1;
                    a=o[a];
                }
                for(auto x:V) o[x]=a;
            }
            else Union(a,b,0);
        }
        for(int i=1;i<=k;i++)
        {
            if(!take[i])
            {
                cout<<-1;
                return 0;
            }
        }
        cout<<ans;
    }


    return 0;
}