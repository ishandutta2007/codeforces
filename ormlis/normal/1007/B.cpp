#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> divs[maxN];

void precalc() {
    for (int i = 1; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    auto da = divs[a], db = divs[b], dc = divs[c];
    int j = 0, e = 0;
    vector<int> cnt(8);
    for (auto &d : da) {
        while (j < (int) db.size() && db[j] < d) j++;
        while (e < (int) dc.size() && dc[e] < d) e++;
        bool hb = (j != db.size() && db[j] == d);
        bool hc = (e != dc.size() && dc[e] == d);
        if (hb && hc) {
            cnt[7]++;
        } else if (hb) {
            cnt[3]++;
        } else if (hc) {
            cnt[5]++;
        }
    }
    cnt[1] = da.size();
    cnt[2] = db.size();
    cnt[4] = dc.size();
    e = 0;
    for (auto &d : db) {
        while (e < (int) dc.size() && dc[e] < d) e++;
        bool hc = (e != dc.size() && dc[e] == d);
        if (hc) {
            cnt[6]++;
        }
    }
    cnt[6] -= cnt[7];
    cnt[1] -= cnt[3] + cnt[5] + cnt[7];
    cnt[2] -= cnt[3] + cnt[6] + cnt[7];
    cnt[4] -= cnt[6] + cnt[5] + cnt[7];
    ll ans = 0;
    range(take1, 8) {
        range(take2, take1 + 1) {
            range(take3, take2 + 1) {
                if ((take1 | take2 | take3) != 7) continue;
                if (__builtin_popcount(take1 | take2) < 2) continue;
                if (__builtin_popcount(take1 | take3) < 2) continue;
                if (__builtin_popcount(take3 | take2) < 2) continue;
                if (take1 == take2 && take1 == take3) {
                    ans += 1ll * (cnt[take1] + 2) * (cnt[take1] + 1) * cnt[take1] / 6;
                    continue;
                }
                if (take1 == take2) {
                    ans += 1ll * (cnt[take1] + 1) * cnt[take1] / 2 * cnt[take3];
                    continue;
                }
                if (take2 == take3) {
                    ans += 1ll * (cnt[take1]) * (cnt[take2] + 1) * (cnt[take2]) / 2;
                    continue;
                }
                ans += 1ll * cnt[take1] * cnt[take2] * cnt[take3];
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    precalc();
    range(_, tests) {
        solve();
    }
    return 0;
}