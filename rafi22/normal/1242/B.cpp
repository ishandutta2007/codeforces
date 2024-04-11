#include <bits/stdc++.h>

//#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>G[100007];

int o[100007];
int s[100007];
int ile[100007];

int Find(int v)
{
    if(o[v]==v) return v;
    return Find(o[v]);
}
void Union(int u,int v)
{
    if(s[u]<s[v])
    {
        o[u]=v;
        s[v]+=s[u];
    }
    else
    {
        o[v]=u;
        s[u]+=s[v];
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
        int n,m,a,b;
        cin>>n>>m;
        int ans=n-1;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            o[i]=i;
            s[i]=1;
        }
        set<int>roots;
        for(int i=1;i<=n;i++)
        {
            for(auto u:G[i]) ile[Find(u)]++;
            vector<int>del;
            for(auto x:roots)
            {
                if(ile[x]==s[x]) continue;
                del.pb(x);
                ans--;
            }
            for(auto u:G[i]) ile[Find(u)]--;
            for(auto x:del)
            {
                Union(x,Find(i));
                roots.erase(x);
            }
            roots.insert(Find(i));
        }
        cout<<ans;
    }

    return 0;
}