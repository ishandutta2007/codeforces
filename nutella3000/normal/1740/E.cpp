#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e9;
const ll mod = 998244353;
const int N = 1e5 + 3;

int n;
vector<int> g[N];
int dp[N][2];
void dfs(int v) {
    dp[v][0] = 1;
    int t = 0;
    for (int to : g[v]) {
        dfs(to);
        t += max(dp[to][0], dp[to][1]);
    }
    dp[v][1] = t;
    for (int to : g[v]) {
        chmax(dp[v][0], dp[to][0] + 1);
    }
}

void run() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        g[p].push_back(i);
    }
    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}