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

int h[200007];
int t[200007];
vector<int>G[200007];
int DP[200007][3];

void dfs(int v,int o)
{
    int in=0,out=0,sum=0;
    vector<int>DPs;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        if(h[u]==h[v])
        {
            DPs.pb(DP[u][1]-DP[u][2]);
            sum+=DP[u][2];
        }
        else if(h[u]>h[v])
        {
            out++;
            sum+=DP[u][1];
        }
        else
        {
            in++;
            sum+=DP[u][2];
        }
    }
    sort(DPs.begin(),DPs.end());
    for(int k=0;k<3;k++)
    {
        DP[v][k]=inf;
        int sum1=sum;
        for(int i=0;i<=sz(DPs);i++)
        {
            DP[v][k]=min(DP[v][k],sum1+(sz(G[v])-min(out+i+(k==2),in+(sz(DPs)-i)+(k==1)))*t[v]);
            if(i!=sz(DPs)) sum1+=DPs[i];
        }
    }
   // cout<<v<<" "<<DP[v][0]<<" "<<DP[v][1]<<" "<<DP[v][2]<<endl;
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
        for(int i=1;i<=n;i++) cin>>t[i];
        for(int i=1;i<=n;i++) cin>>h[i];
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        cout<<DP[1][0];
    }

    return 0;
}