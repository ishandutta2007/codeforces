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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct fenwick {
    vector<int> a{};
    int n{};

    void build(int k) {
        n = k;
        a.resize(n);
    }

    void upd(int i, int x) {
        for(; i < n; i = i | (i + 1)) a[i] += x;
    }

    int get(int i) {
        int res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) res += a[i];
        return res;
    }
};



void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];

    fenwick f1, f2;
    f1.build(n+10);
    f2.build(n+10);

    vector<vector<pair<int, int>>> req(n);
    range(i, q) {
        int x, y; cin >> x >> y;
        req[n - y - 1].emplace_back(x, i);
    }
    vector<int> ans(q);
    range(i, n) {
        int e = i + 1 - a[i];
        if (e >= 0) {
            int l = -1, r = i + 1;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                if (f1.get(mid) >= e) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            f1.upd(0, 1);
            f1.upd(l + 1, -1);
            f2.upd(l + 1, 1);
        } else {
            f2.upd(0, 1);
        }
        for(auto &p: req[i]) {
            ans[p.second] = i + 1 - f2.get(p.first);
        }
    }
    range(i, q) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}