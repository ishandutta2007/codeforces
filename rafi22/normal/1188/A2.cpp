#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

vector<pair<int,int>>G[100007];
vector<pair<pair<int,int>,int>>ans;
vector<pair<int,int>>vec[100007];
int R;

void dfs(int v,int o,int k)
{
    int sum=0;
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        dfs(u.st,v,u.nd);
        sum+=u.nd;
        for(auto x:vec[u.st]) vec[v].pb(x);
    }
    if(v==R) for(auto x:vec[v]) ans.pb({{R,x.st},x.nd});
    else if(sz(G[v])==1) vec[v].pb({v,k});
    else
    {
        vec[v][0].nd-=(sum-k)/2;
        vec[v].back().nd-=(sum-k)/2;
        ans.pb({{vec[v][0].st,vec[v].back().st},(sum-k)/2});
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
        int n,a,b,c;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b>>c;
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        for(int i=1;i<=n;i++)
        {
            if(sz(G[i])==2)
            {
                cout<<"NO";
                return 0;
            }
            if(sz(G[i])==1) R=i;
        }
        cout<<"YES"<<endl;
        //return 0;
        dfs(R,-1,0);
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st.st<<" "<<x.st.nd<<" "<<x.nd<<endl;
    }

    return 0;
}