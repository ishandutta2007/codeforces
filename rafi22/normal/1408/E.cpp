#include <bits/stdc++.h>

#define int long long
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
int a[100007];
int b[100007];
int o[200007];
int s[200007];
int Find(int a)
{
    while(true)
    {
        if(o[a]==a)
        {
            return a;
        }
        a=o[a];
    }
}
void Union(int u,int v)
{
    if(s[u]<=s[v])
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
vector<pair<int,pair<int,int>>>edge;

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
        int n,m,ans=0;
        cin>>m>>n;
        for(int i=1;i<=m;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n+m;i++)
        {
            o[i]=i;
            s[i]=1;
        }
        for(int i=1;i<=m;i++)
        {
            int k,x;
            cin>>k;
            while(k--)
            {
                cin>>x;
                edge.pb({a[i]+b[x],{i,m+x}});
                ans+=a[i]+b[x];
            }
        }
        sort(edge.begin(),edge.end(),greater<pair<int,pair<int,int>>>());
        for(auto xd:edge)
        {
            if(Find(xd.nd.st)!=Find(xd.nd.nd))
            {
                Union(Find(xd.nd.st),Find(xd.nd.nd));
                ans-=xd.st;
            }
        }
        cout<<ans;
    }

    return 0;
}