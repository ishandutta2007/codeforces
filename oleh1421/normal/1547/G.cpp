//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
vector<int>g[N];
vector<int>rg[N];
bool used[N];
vector<int>order;
void dfs(int v){
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
    order.push_back(v);
}
int cmp[N];
void dfs1(int v){
    for (int to:rg[v]){
        if (!cmp[to]){
            cmp[to]=cmp[v];
            dfs1(to);
        }
    }
}
vector<int>G[N];
bool cyc[N];
int dp[N];
void dfs2(int v){
    used[v]=true;
    if (v==cmp[1]){
        dp[v]=0;
        if (cyc[v]) dp[v]=2;
        return;
    }
    dp[v]=-1;
    for (int to:G[v]){
        if (!used[to]){
            dfs2(to);
        }
        if (dp[v]==-1){
            dp[v]=dp[to];
            if (cyc[v] && dp[v]!=-1) dp[v]=2;
        } else if (dp[v]==0){
            if (dp[to]>=0){
                if (dp[to]<=1) dp[v]=1;
                else dp[v]=2;
            }
        } else if (dp[v]==1){
            if (dp[to]==2) dp[v]=2;
        } else {

        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    order.clear();
    for (int i=1;i<=n;i++){
        g[i].clear();
        rg[i].clear();
        cmp[i]=0;
        used[i]=false;
        G[i].clear();
        cyc[i]=false;
    }
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            dfs(i);
        }
    }
    reverse(order.begin(),order.end());
    int cnt=0;
    for (int i:order){
        if (!cmp[i]){
            cmp[i]=++cnt;
            dfs1(i);
        }
    }
    for (int i=1;i<=n;i++){
        for (int to:rg[i]){
            if (cmp[i]!=cmp[to]){
                G[cmp[i]].push_back(cmp[to]);
            } else {
                cyc[cmp[i]]=true;
            }
        }
    }
    for (int i=1;i<=cnt;i++) used[i]=false;
    for (int i=1;i<=cnt;i++){
        dfs2(i);
    }
    map<int,int>mp;
    mp[-1]=0;
    mp[0]=1;
    mp[1]=2;
    mp[2]=-1;
//    cout<<cnt<<" "<<cmp[n]<<" "<<dp[cmp[n]]<<endl;
    for (int i=1;i<=n;i++) cout<<mp[dp[cmp[i]]]<<" ";
    cout<<endl;

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 4
1 2
2 3
1 4
4 3
**/