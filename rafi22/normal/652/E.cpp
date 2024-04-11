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

const bool multi=0;

vector<pair<int,bool> >G[300007];
vector<pair<int,bool> > G1[300007];
int nr[300007],c=1,low[300007];
bool odw[300007],odw1[300007],odw2[300007];
int sp[300007],s,oj[300007];
bool is[300007],kr[300007],ans[300007];

void dfs(int v,int o)
{
    odw[v]=1;
    nr[v]=c++;
    low[v]=nr[v];
    for(auto u:G[v])
    {
        if(!odw[u.st])
        {
            dfs(u.st,v);
            low[v]=min(low[v],low[u.st]);
        }
        else if(u.st!=o)
        {
            low[v]=min(low[v],nr[u.st]);
        }
    }
}
void dfs1(int v,int o)
{
    odw1[v]=1;
    for(auto u:G[v])
    {
        if(!odw1[u.st])
        {
            if(low[u.st]==nr[u.st])
            {
                sp[u.st]=++s;
                oj[s]=sp[v];
                kr[s]=u.nd;
            }
            else
            {
                sp[u.st]=sp[v];
                is[sp[v]]|=u.nd;
            }
            dfs1(u.st,v);
        }
        else if(u.st!=o) is[sp[v]]|=u.nd;
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
        int n,m,a,b,p,k;
        bool c;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        cin>>p>>k;
        dfs(1,-1);
        sp[1]=++s;
        dfs1(1,-1);
        int v=sp[p];
        bool act=0;
        while(true)
        {
            odw2[v]=1;
            act|=is[v];
            ans[v]=act;
            if(v==1) break;
            act|=kr[v];
            v=oj[v];
        }
        v=sp[k];
        act=0;
        while(true)
        {
            act|=is[v];
            if(odw2[v])
            {
                if(ans[v]|act) cout<<"YES";
                else cout<<"NO";
                break;
            }
            act|=kr[v];
            v=oj[v];
        }
    }
    return 0;
}