#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace __gnu_pbds;
using namespace std;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 80;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

int check(int a, int b, int c) {
    return min(c % b, b - c % b);
}

void solve() {
    vector<vector<int>> del(20001);
    for(int i = 1; i <= 20000; ++i) {
        for(int j = i; j <= 20000; j += i) {
            del[j].push_back(i);
        }
    }
    int q; cin >> q;
    range(i, q) {
        int a, b, c; cin >> a >> b >> c;
        int ans = c-a;
        vector<int> answ = {b, b, b};
        for(int b1 = max(b-ans, 1); b1 < min(20001, b+ans); ++b1) {
            int c1 = c, a1 = a;
            int cur = abs(b1-b);
            if (b1 > c) {
                cur += b1 - c;
                c1 = b1;
            } else {
                if (c1 % b1 < b1 - c1 % b1) {
                    cur += c1 % b1;
                    c1 -= c1 % b1;
                } else {
                    cur += b1 - c1 % b1;
                    c1 += b1 - c1 % b1;
                }
            }
            if (cur > ans) continue;
            if (a1 > b1) {
                cur += a1 - b1;
                a1 = b1;
            } else if (b1 % a1) {
                auto x = lower_bound(all(del[b1]), a1);
                auto x1 = *x;
                --x;
                auto x2 = *x;
                if (x1 - a1 > a1 - x2) {
                    cur += a1 - x2;
                    a1 = x2;
                } else {
                    cur += x1 - a1;
                    a1 = x1;
                }
            }
            if (ans > cur) {
                ans = cur;
                answ = {a1, b1, c1};
            }
        }
        cout << ans << "\n";
        cout << answ[0] << " " << answ[1] << " " << answ[2] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}