#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> stk;
    vector<ll> need_add;
    ll S = 0, B = 0;
    stk.emplace_back(0, 0);
    range(_, m) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            cin >> k;
            n += k;
            stk.clear();
            stk.emplace_back(0, 0);
            S = B = 0;
            need_add.clear();
        } else if (t == 2) {
            int k;
            cin >> k;
            ll value = 1ll * stk.back().first * S + B + stk.back().second;
            if (value == 0) {
                n += k;
            } else {
                ll must = 1ll * n * S + B;
                while (true) {
                    ll d = n - stk.back().first;
                    value = 1ll * stk.back().first * S + B + stk.back().second;
                    ll to = S + (value + d - 1) / d;
                    if (!need_add.empty() && need_add.back() <= to) {
                        need_add.pop_back();
                        stk.pop_back();
                        continue;
                    }
                    need_add.push_back(to);
                    stk.emplace_back(n, -must);
                    n += k;
                    break;
                }
            }
        } else if (t == 3) {
            ll b, s;
            cin >> b >> s;
            S += s;
            B += b;
            while (!need_add.empty() && need_add.back() <= S) {
                need_add.pop_back();
                stk.pop_back();
            }
        }
        ll value = 1ll * stk.back().first * S + B + stk.back().second;
        cout << stk.back().first + 1 << ' ' << value << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}