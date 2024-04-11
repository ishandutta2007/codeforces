#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 4e6;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; ll S; cin >> n >> S;
    vector<vector<pair<int, ll>>> g(n);
    range(i, n-1) {
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int root = 0;
    ll ans = 0;
    vector<ll> answers;
    function<int(int, int)> dfs = [&] (int v, int p) {
        int res = 0;
        for(auto &[u, w]: g[v]) {
            if (u == p) continue;
            int k = dfs(u, v);
            res += k;
            ans += w * k;
            while(w != 0) {
                answers.emplace_back((-w + w/2) * k);
                w/=2;
            }
        }
        return max(1, res);
    };
    dfs(root, -1);
    sort(all(answers));
    range(i, (int)answers.size()+1) {
        if (S >= ans) {
            cout << i << "\n";
            return;
        }
        ans += answers[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}