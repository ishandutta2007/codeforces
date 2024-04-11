//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400004;
int d[N];
vector<int>g[N];
vector<int>gg[N];
bool used[N];
int dp[N];
void dfs(int v){
    used[v]=true;
    for (int to:gg[v]){
        if (!used[to]) dfs(to);
        dp[v]=min(dp[v],dp[to]);
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        g[i].clear();
        gg[i].clear();
        d[i]=-1;
        used[i]=false;
    }
    for (int i=1;i<=m;++i){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
//        g[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    d[1]=0;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (int to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    for (int i=1;i<=n;i++){
        dp[i]=d[i];
        for (int to:g[i]){
            if (d[to]>d[i]){
                gg[i].push_back(to);

            } else {
                dp[i]=min(dp[i],d[to]);
            }
        }
    }
    dfs(1);
    for (int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;


}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*
1
6 8
1 2
1 5
2 6
6 1
2 3
3 4
4 2
5 4
*/