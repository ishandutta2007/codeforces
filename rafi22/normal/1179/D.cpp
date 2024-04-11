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

int DP[500007];
int s[500007];
vector<int>G[500007];
int ans=inf,n;

void dfs(int v,int o)
{
    s[v]=1;
    vector<pair<pair<int,int>,int>>DPs;
    DP[v]=inf;
    if(sz(G[v])==1) DP[v]=0;
    int sum=0;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        s[v]+=s[u];
        DPs.pb({{-2*s[u],2*DP[u]+s[u]*(s[u]+1)},u});
    }
    sort(DPs.begin(),DPs.end());
    vector<pair<int,int>>CHT;
    for(auto x:DPs)
    {
        int l=0,r=sz(CHT)-1,sr;
        int S=n-s[x.nd];
        ans=min(ans,2*DP[x.nd]+(n-s[x.nd])*(n-s[x.nd]-1));
        while(l<=r)
        {
            sr=(l+r)/2;
            int L=2*DP[x.nd]+S*(S-1)+S*CHT[sr].st+CHT[sr].nd;
            ans=min(ans,L);
            if(sr+1==sz(CHT)) break;
            int R=2*DP[x.nd]+S*(S-1)+S*CHT[sr+1].st+CHT[sr+1].nd;
            ans=min(ans,R);
            if(L<=R) r=sr-1;
            else l=sr+1;
        }
        if(sz(CHT)==0||x.st.st!=CHT.back().st) CHT.pb({x.st.st,x.st.nd});
        DP[v]=min(DP[v],DP[x.nd]+(s[v]-s[x.nd])*(s[v]-s[x.nd]-1)/2);
    }
    //cout<<v<<" "<<DP[v]<<endl;
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
        int a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        ans/=2;
        cout<<ans+2*(n*(n-1)/2-ans);
    }

    return 0;
}