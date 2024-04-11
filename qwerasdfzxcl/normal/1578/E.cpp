#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], cur, dp[100100], dp2[100100];
vector<int> adj[100100];
bool ans;

void dfs(int s, int pa = -1){
    dp[s] = a[s];
    int cnt = 0;
    for (auto &v:adj[s]) if (v!=pa){
        dfs(v, s);
        dp[s] ^= dp[v];
        dp2[s] |= dp2[v];
        if (dp2[v]) cnt++;
    }
    if (cnt>=2) ans = 1;
    if (dp[s]==cur) dp2[s] = 1;
    if (dp[s]==0 && dp2[s]) ans = 1;
}

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    cur = 0;
    ans = 0;
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        cur ^= a[i];
    }
    for (int i=0;i<n-1;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (!cur) printf("YES\n");
    else{
        dfs(1);
        if (ans && k>=3) printf("YES\n");
        else printf("NO\n");
    }

    ///init
    for (int i=0;i<=n;i++){
        adj[i].clear();
        dp[i] = 0, dp2[i] = 0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}