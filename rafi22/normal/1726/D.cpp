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

const int N=1000007;

vector<pair<int,int>>G[N];
bool odw[N];
int d[N];
int k[N];
vector<pair<pair<int,int>,int>>V;
bool ans[N];

void dfs(int v,int o)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u.st])
        {
            d[u.st]=d[v]+1;
            k[u.st]=u.nd;
            dfs(u.st,v);
        }
        else if(d[u.st]<d[v]&&u.st!=o) V.pb({{u.st,v},u.nd});
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb({b,i});
            G[b].pb({a,i});
        }
        dfs(1,0);
        set<int>S;
        for(auto x:V)
        {
            S.insert(x.st.st);
            S.insert(x.st.nd);
            ans[x.nd]=1;
        }
        if(sz(V)==3&&sz(S)==3)
        {
            int mx=-inf,p;
            for(auto x:V)
            {
                int c=d[x.st.nd]-d[x.st.st];
                if(c>mx)
                {
                    mx=c;
                    p=x.nd;
                }
            }
            ans[p]=0;
            mx=-inf;
            for(auto x:V)
            {
                if(d[x.st.nd]>mx)
                {
                    mx=d[x.st.nd];
                    p=x.st.nd;
                }
            }
            ans[k[p]]=1;
        }
        for(int i=1;i<=m;i++) cout<<ans[i];
        cout<<endl;
        for(int i=1;i<=max(n,m);i++)
        {
            G[i].clear();
            odw[i]=0;
            ans[i]=0;
            d[i]=0;
            k[i]=0;
        }
        V.clear();
    }

    return 0;
}