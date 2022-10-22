#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> adj;
int L[200005];
int R[200005];
int ans = 0;
int dfs(int c, int p) {
    int sum = 0;
    for(int n : adj[c]) {
        if(n==p) continue;
        sum += dfs(n, c);
    }
    if(sum < L[c]) {
        ans++;
        return R[c];
    }
    return min(sum, R[c]);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        adj.clear();
        adj.resize(N);
        for(i=1;i<N;i++) {
            int a;
            cin >> a;
            a--;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
        for(i=0;i<N;i++) cin >> L[i] >> R[i];
        ans = 0;
        dfs(0, -1);
        cout << ans << '\n';
    }
}