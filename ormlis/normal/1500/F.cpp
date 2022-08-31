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
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct dp_with_backs {
    ll add = 0;
    ll cx = 1;
    deque<pair<ll, ll>> segs;
    vector<ar<ll, 3>> changes;

    void change(ll k) {
        cx *= -1;
        add *= -1;
        add += k;
        changes.push_back({-1, -1, k});
    }

    int get_version() {
        return changes.size();
    }

    void go_to(int v) {
        assert(changes.size() >= v);
        while (changes.size() != v) {
            auto[a, b, c] = changes.back();
            changes.pop_back();
            if (a == 0) {
                segs.emplace_back(b, c);
            } else if (a == 1) {
                segs.pop_back();
            } else if (a == 2) {
                segs.emplace_front(b, c);
            } else if (a == 3) {
                segs.pop_front();
            } else if (a == -1) {
                add -= c;
                add *= -1;
                cx *= -1;
            } else if (a == 5) {
                cx = b;
                add = c;
                segs.pop_back();
            } else {
                assert(0);
            }
        }
    }

    void del_bigger(ll x) {
        if (cx > 0) {
            x -= add;
            while (!segs.empty()) {
                auto[l, r] = segs.back();
                if (r <= x) break;
                changes.push_back({0, segs.back().first, segs.back().second});
                if (l > x) {
                    segs.pop_back();
                } else {
                    segs.back().second = x;
                    changes.push_back({1, segs.back().first, segs.back().second});
                }
            }
        } else {
            x = -x + add;
            while (!segs.empty()) {
                auto[l, r] = segs.front();
                if (l >= x) break;
                changes.push_back({2, segs.front().first, segs.front().second});
                if (r < x) {
                    segs.pop_front();
                } else {
                    segs.front().first = x;
                    changes.push_back({3, segs.front().first, segs.front().second});
                }
            }
        }
    }

    void push_back(ll x) {
        if (cx < 0) {
            x = -x + add;
            segs.push_front({x, x});
            changes.push_back({3, segs.front().first, segs.front().second});
        } else {
            x -= add;
            segs.emplace_back(x, x);
            changes.push_back({1, segs.back().first, segs.back().second});
        }
    }

    ll back() {
        if (segs.empty()) return -INF;
        if (cx < 0) {
            return -segs.front().first + add;
        } else {
            return segs.back().second + add;
        }
    }

    void clear(ll x) {
        while (!segs.empty()) {
            changes.push_back({0, segs.back().first, segs.back().second});
            segs.pop_back();
        }
        changes.push_back({5, cx, add});
        cx = 1;
        add = 0;
        segs.emplace_back(0, x);
    }

    void print() {
        for(auto [l, r] : segs) {
            l = l * cx + add;
            r = r * cx + add;
            cout << l << ' ' << r << '\n';
        }
        cout << "END\n";
    }

};

void solve() {
    int n;
    ll C;
    cin >> n >> C;
    vector<ll> w(n - 1);
    range(i, n - 2) cin >> w[i + 1];
    dp_with_backs dp;
    dp.clear(C);
    vector<int> dpstate(n - 1);
    for (int i = 1; i <= n - 2; ++i) {
        //dp.print();
        dp.del_bigger(w[i]);
        if (dp.segs.empty()) {
            cout << "NO\n";
            return;
        }
        dpstate[i] = dp.get_version();
        if (dp.back() == w[i]) {
            dp.clear(w[i]);
        } else {
            dp.change(w[i]);
            if (dp.back() != w[i]) dp.push_back(w[i]);
        }
    }
    vector<ll> a(n);
    a[n - 1] = 0;
    ll x = dp.back();
    for (int i = n - 2; i >= 0; --i) {
        a[i] = a[i + 1] + x;
        if (i == 0) break;
        dp.go_to(dpstate[i]);
        ll cx = 1;
        if (x < 0) {
            cx = -1;
            x *= -1;
        }
        if (dp.back() == w[i]) {
            x = -w[i] * cx;
        } else if (x == w[i]) {
            x = -dp.back() * cx;
        } else {
            x = w[i] - x;
            x *= cx;
        }
    }
    cout << "YES\n";
    ll min_el = *min_element(all(a));
    for (auto &s : a) cout << s - min_el << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}