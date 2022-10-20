#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int K = 1300;

int n;
vector<int> adj[N];
int res[N];
int ls[N];
int cnt;
int par[N];

void dfs(int u, int p) {
    par[u] = p;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    ls[++cnt] = u;
}

pair<int, int> dp[N];

int getRes(int sz) {
   for (int i = 1; i <= n; i++) {
       int u = ls[i];
       dp[u] = make_pair(0, 0);
       pair<int, int> mx(0, 0);
       for (int v : adj[u]) {
           if (v == par[u]) {
               continue;
           }
           dp[u].first += dp[v].first;
           if (dp[v].second > mx.second) {
               mx.second = dp[v].second;
           }
           if (mx.first < mx.second) {
               swap(mx.first, mx.second);
           }
       }
       if (mx.first + mx.second + 1 >= sz) {
           dp[u].first++;
           dp[u].second = 0;
       } else {
           dp[u].second = mx.first + 1;
       }
   }
   return dp[1].first;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= min(n, K); i++) {
        res[i] = getRes(i);
    }
    int x = res[min(n, K)];
    int last = min(n, K);
    for (int i = x; i > 0; i--) {
        int low = last, high = n + 1;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            int foo = getRes(mid);
            if (foo < i) {
                high = mid;
            } else {
                low = mid;
            }
        }
        for (int j = last + 1; j <= low; j++) {
            res[j] = i;
        }
        last = low;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}