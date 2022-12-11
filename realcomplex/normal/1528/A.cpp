#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
ll L[N], R[N];
vector<int> T[N];

ll dp[N][2];

void dfs(int u, int pp){
    dp[u][0] = dp[u][1] = 0;
    for(auto x : T[u]){
        if(x == pp) continue;
        dfs(x, u);
        dp[u][0] += max(dp[x][0] + abs(L[u] - L[x]), dp[x][1] + abs(L[u] - R[x]));
        dp[u][1] += max(dp[x][0] + abs(R[u] - L[x]), dp[x][1] + abs(R[u] - R[x]));
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
    }
    int u, v;
    for(int i = 1; i <= n; i ++ ){
        cin >> L[i] >> R[i];
    }
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1,-1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}