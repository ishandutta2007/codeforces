//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < n; ++i)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()


using namespace std;

typedef long long ll;
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5+1;
const int md = 998244353;

vector<int> g[maxN], gr[maxN];

void solve() {
    int n, m; cin >> n >> m;
    range(i, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    int k; cin >> k;
    vector<int> p(k);
    range(i, k) cin >> p[i];
    queue<int> q;
    vector<int> ans(n+1, INFi), cnt(n+1, 0);
    q.push(p.back());
    ans[p.back()] = 0;
    cnt[p.back()] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto u: gr[v]) {
            if (ans[u] > ans[v] + 1) {
                ans[u] = ans[v] + 1;
                cnt[u] = 0;
                q.push(u);
            }
            if (ans[u] == ans[v] + 1) cnt[u]++;
        }
    }
    int ansmax = 0, ansmin = 0;
    range(i, k-1) {
        if(ans[p[i]] != ans[p[i+1]] + 1) {
            ansmin++;
            ansmax++;
        }
        else if (cnt[p[i]] != 1) {
            ansmax++;
        }
    }
    cout << ansmin << " " << ansmax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //auto sad = mt19937(2231337);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}