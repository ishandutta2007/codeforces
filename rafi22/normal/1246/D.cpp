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

int s[100007];
int p[100007];
vector<int>G[100007];
int xd[100007];
bool is[100007];

void dfs(int v)
{
    s[v]=1;
    for(auto u:G[v])
    {
        dfs(u);
        if(s[u]+1>s[v])
        {
            xd[v]=u;
            s[v]=s[u]+1;
        }
    }
}

bool cmp(int l,int r){ return s[l]>s[r];}

vector<int>ans,ans1;

void dfs1(int v)
{
    if(!xd[v]) return ;
    int o=xd[v];
    for(auto u:G[v])
    {
        if(u!=o)
        {
            p[xd[v]]=u;
            ans.pb(xd[v]);
            xd[u]=xd[v];
            xd[v]=u;
        }
        dfs1(u);
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
        int n,a;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a;
            p[i]=a;
            G[a].pb(i);
        }
        dfs(0);
        dfs1(0);
        for(int i=1;i<n;i++) is[p[i]]=1;
        for(int i=0;i<n;i++)
        {
            if(is[i]) continue;
            int v=i;
            while(true)
            {
                ans1.pb(v);
                if(v==0) break;
                v=p[v];
            }
        }
        reverse(ans1.begin(),ans1.end());
        for(auto x:ans1) cout<<x<<" ";
        cout<<endl;
        cout<<sz(ans)<<endl;
        reverse(ans.begin(),ans.end());
        for(auto x:ans) cout<<x<<" ";
    }

    return 0;
}