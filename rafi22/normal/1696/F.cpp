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

const int N=107;

bool is[N][N][N];
bool odw[N];
bool was[N];
int n;

void dfs(int v,int r)
{
    odw[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(!odw[i]&&!was[v]&&is[v][i][r]) dfs(i,r);
    }
}

set<int>G[N];

void check(int v,int u)
{
    odw[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(is[i][u][v])
        {
            G[i].insert(v);
            G[v].insert(i);
            if(!odw[i]) check(i,v);
        }
    }
}

int d[N][N];

void dfs1(int v,int o,int r)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(odw[u]) continue;
        d[r][u]=d[r][v]+1;
        dfs1(u,v,r);
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
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                string s;
                cin>>s;
                for(int k=0;k<n;k++)
                {
                    is[i][j][k+1]=s[k]-'0';
                    is[j][i][k+1]=s[k]-'0';
                }
            }
            for(int j=1;j<=n;j++) is[i][i][j]=1;
        }
        memset(was,0,sizeof was);
        for(int q=0;q<n-2;q++)
        {
            int mx=-1,v;
            for(int r=1;r<=n;r++)
            {
                if(was[r]) continue;
                memset(odw,0,sizeof odw);
                int c=0;
                for(int i=1;i<=n;i++)
                {
                    if(was[i]||odw[i]) continue;
                    dfs(i,r);
                    c++;
                }
                if(c>mx)
                {
                    mx=c;
                    v=r;
                }
            }
            was[v]=1;
        }
        int a=-1,b=-1;
        for(int i=1;i<=n;i++)
        {
            if(!was[i])
            {
                if(a==-1) a=i;
                else b=i;
            }
        }
        memset(odw,0,sizeof odw);
        for(int i=1;i<=n;i++) G[i].clear();
        G[a].insert(b);
        G[b].insert(a);
        check(a,b);
        check(b,a);
        memset(d,-1,sizeof d);
        bool ok=1;
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++)
        {
            for(auto j:G[i]) if(j<i) ans.pb({i,j});
        }
        if(sz(ans)!=n-1) ok=0;
        for(int i=1;i<=n;i++)
        {
            memset(odw,0,sizeof odw);
            d[i][i]=0;
            dfs1(i,0,i);
            for(int j=1;j<=n;j++) if(d[i][j]==-1) ok=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(is[i][j][k]!=(d[i][k]==d[j][k])) ok=0;
                }
            }
        }
        if(!ok)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}