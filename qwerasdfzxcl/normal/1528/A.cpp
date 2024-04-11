#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[100100];
pair<int, int> lr[100100];
ll dp[100100][2];

ll myabs(ll x){
    if (x<0) return -x;
    return x;
}

void dfs(int s, int pa = -1){
    for (auto &v:adj[s]) if (v!=pa){
        dfs(v, s);
        int x = lr[v].first, y = lr[v].second;
        dp[s][0] += max(myabs(lr[s].first-x)+dp[v][0], myabs(lr[s].first-y)+dp[v][1]);
        dp[s][1] += max(myabs(lr[s].second-x)+dp[v][0], myabs(lr[s].second-y)+dp[v][1]);
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d %d", &lr[i].first, &lr[i].second);
    }
    for (int i=1;i<=n;i++) dp[i][0] = dp[i][1] = 0;
    for (int i=0;i<n-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
    for (int i=1;i<=n;i++) adj[i].clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}