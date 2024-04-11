#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

vector <int> G[100007];
int s[100007];
int leaf[100007];
bool odw[100007];
vector <int> c;
int mini=inf;
int n,a,b;

void dfs(int v)
{
    odw[v]=1;
    s[v]=1;
    int mx=-inf;
    if(G[v].size()==1) leaf[v]=v;
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            dfs(u);
            s[v]+=s[u];
            mx=max(mx,s[u]);
            leaf[v]=leaf[u];
        }
    }
    if(max(n-s[v],mx)<mini)
    {
        c.clear();
        mini=max(n-s[v],mx);
        c.pb(v);
    }
    else if(max(n-s[v],mx)==mini) c.pb(v);
}

void clean()
{
    mini=inf;
    for(int i=0;i<=n;i++)
    {
        odw[i]=0;
        leaf[i]=0;
        G[i].clear();
        s[i]=0;
    }
    c.clear();
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
        int p,k;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
            p=a;
            k=b;
        }
        dfs(1);
        //cout<<c.size()<<endl;
        if(c.size()==1) cout<<p<<" "<<k<<endl<<p<<" "<<k<<endl;
        else
        {
            cout<<leaf[c[0]]<<" "<<G[leaf[c[0]]][0]<<endl<<leaf[c[0]]<<" "<<c[1]<<endl;
        }
        clean();
    }

    return 0;
}