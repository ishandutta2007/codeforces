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

int tab[200007];
int val[200007];
int DP[200007];
vector <int> G[200007];
vector <int> kolejka;
vector <pair<int,int> > kolejka1;
vector <pair<pair<int,int>,int > >ans;
bool odw[200007];
int res=0;
void dfs(int v,int s)
{
    DP[v]=val[v];
    for(auto u:G[v])
    {
        dfs(u,s-1);
        if(DP[u]>0)
        {
            DP[v]+=DP[u];
        }
        else
        {
            kolejka1.pb({s,u});
        }
    }
    res+=DP[v];
}
int c=1;
void dfs1(int v,int s)
{
    odw[v]=1;
    ans.pb({{c,s},v});
    //cout<<v<<endl;
    for(auto u:G[v])
    {
        if(!odw[u]) dfs1(u,s+1);
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>val[i];
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
            if(tab[i]!=-1) G[tab[i]].pb(i);
            else kolejka.pb(i);
        }
        for(int i=0;i<kolejka.size();i++)
        {
            dfs(kolejka[i],10000000);
        }
        cout<<res<<endl;
        sort(kolejka1.begin(),kolejka1.end());
        for(int i=0;i<kolejka1.size();i++)
        {
            dfs1(kolejka1[i].nd,10000000);
            c++;
        }
        for(int i=kolejka.size()-1;i>=0;i--)
        {
            dfs1(kolejka[i],10000000);
            c++;
        }
        sort(ans.begin(),ans.end());
        for(int i=n-1;i>=0;i--) cout<<ans[i].nd<<" ";

    }
    return 0;
}