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
    vector<vector<ar<int, 3>>> g(n);
    range(i, n-1) {
        int u, v, c, w; cin >> u >> v >> w >> c;
        u--; v--; c--;
        g[u].push_back({v, w, c});
        g[v].push_back({u, w, c});
    }
    int root = 0;
    ll ans = 0;
    vector<vector<ll>> answers(2);
    function<int(int, int)> dfs = [&] (int v, int p) {
        int res = 0;
        for(auto &[u, w, c]: g[v]) {
            if (u == p) continue;
            int k = dfs(u, v);
            res += k;
            ans += 1ll * w * k;
            while(w != 0) {
                answers[c].emplace_back(1ll * (-w + w/2) * k);
                w/=2;
            }
        }
        return max(1, res);
    };
    dfs(root, -1);
    sort(rall(answers[0]));
    sort(rall(answers[1]));
    int ogo = 0;
    vector<ll> vz;
    while(ans > S) {
        if (answers[0].empty()) {
            ogo += 2;
            ans += answers[1].back();
            answers[1].pop_back();
            continue;
        }
        if (answers[1].empty()) {
            ogo++;
            ans += answers[0].back();
            vz.push_back(answers[0].back());
            answers[0].pop_back();
            continue;
        }
        ll x = answers[0].back();
        if (x + ans <= S) {
            ogo++;
            ans += x;
            vz.push_back(answers[0].back());
            break;
        }
        if (answers[0].size() == 1) {
            ogo += 2;
            ans += answers[1].back();
            answers[1].pop_back();
            continue;
        }
        x += answers[0][(int)answers[0].size()-1];
        if (x < answers[1].back()) {
            ogo += 1;
            ans += answers[0].back();
            vz.push_back(answers[0].back());
            answers[0].pop_back();
            continue;
        }
        ogo += 2;
        ans += answers[1].back();
        answers[1].pop_back();
    }
    while(!vz.empty() && ans-vz.back() <= S) {
        ogo--;
        ans -= vz.back();
        vz.pop_back();
    }
    cout << ogo << "\n";
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