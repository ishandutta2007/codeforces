#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e5 + 50;
vector<int> g[maxn];
int sz[maxn], dp[maxn][2], ans[maxn];
int n;
void init(){
    scanf("%d", &n); for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
    }
}
void dfs(int u, int f){
    sz[u] = g[u].size();
    if(u != 1) sz[u]--;
    dp[u][0] = dp[u][1] = sz[u];
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == f) continue;
        dfs(v, u);
        int t = dp[v][0]+sz[u];
        if(dp[u][0] < t){
            dp[u][1] = dp[u][0];
            dp[u][0] = t;
        }
        else if(dp[u][1] < t) dp[u][1] = t;
    }
}
void DFS(int u, int f){
    if(u != 1) dp[u][0]++, dp[u][1]++;
    if( (dp[u][0]-1+sz[f] + (f != 1) ) != dp[f][0]){
        //cout<<"u:"<<u<<endl;
        int t = dp[f][0]-1+sz[u]+(u!=1);
        if(dp[u][0] < t){
            dp[u][1] = dp[u][0];
            dp[u][0] = t;
        }
        else if(dp[u][1] < t) dp[u][1] = t;
    }
    else{
        int t = dp[f][1]-1+sz[u]+(u!=1);
        if(dp[u][0] < t){
            dp[u][1] = dp[u][0];
            dp[u][0] = t;
        }
        else if(dp[u][1] < t) dp[u][1] = t;
    }
    ans[u] = dp[u][0] + dp[u][1] - g[u].size() + 1;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == f) continue;
        DFS(v, u);
    }
}
void sol(){
    dfs(1, 1);
    //ans[1] = dp[1][0] + dp[1][1] - sz[1] + 1;
    DFS(1, 0);
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        //cout<<"i:"<<i<<" ans:"<<dp[i][0]<<" "<<dp[i][1]<<endl;
        mx = max(mx, ans[i]);
    }
    printf("%d\n", mx);
}
int main()
{
	int T; cin>>T;
	while(T--){
        init(); sol();
	}
}