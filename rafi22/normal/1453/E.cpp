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

const bool multi=1;

int ans;
int DP[200007];
bool odw[200007];
vector<int> G[200007];
void dfs(int v)
{
    vector<int>vec;
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            dfs(u);
            vec.pb(DP[u]);
        }
    }
    sort(vec.begin(),vec.end());
    if(sz(vec)>0)
    {
        DP[v]=vec[0]+1;
        if(v==1)
        {
            ans=max(ans,vec.back()+1);
            if(sz(vec)>1) ans=max(ans,vec[sz(vec)-2]+2);
        }
        else ans=max(ans,vec.back()+2);
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            odw[i]=0;
            DP[i]=0;
        }
        ans=0;
    }

    return 0;
}