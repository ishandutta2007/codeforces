#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;

int n;
vector<int> gr[N];
int dp[N];

int dfs(int v, int k, int pr = -1) {
    dp[v] = 0;
    int r = 0;
    for (int to : gr[v]) {
        if (to == pr) continue;
        r += dfs(to, k, v);
        chmax(dp[v], dp[to] + 1);
    }
    if (v != 0 && pr != 0 && dp[v] == k-1) {
        dp[v] = -1;
        ++r;
    }
    return r;
}

void run() {
    int cnt;
    cin >> n >> cnt;
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        gr[p].push_back(i);
    }
    int l = 0, r = n+1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (dfs(0, mid) <= cnt) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}