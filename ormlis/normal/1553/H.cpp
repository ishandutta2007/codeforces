#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
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

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int md = 31607;
const ll INF = 2e18;
const int K = 19;
const int maxN = 1 << K;


double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

bool has[maxN];
int mx[maxN];
int mn[maxN];
int ans[K][maxN];

void rec(int l, int k) {
    if (k == 0) {
        if (has[l]) {
            mx[l] = mn[l] = l;
        }
        return;
    }
    rec(l, k - 1);
    rec(l + (1 << (k - 1)), k - 1);
    int l2 = l + (1 << (k - 1));
    if (mn[l] == -1 && mn[l2] == -1) return;
    int t = 1 << (k - 1);
    if (mn[l] == -1) {
        range(x, t) {
            mn[l + x] = mn[l2 + x];
            mx[l + x] = mx[l2 + x];
            mn[l2 + x] = t ^ mn[l + x];
            mx[l2 + x] = t ^ mx[l + x];
        }
        return;
    }
    if (mn[l2] == -1) {
        range(x, t) {
            mn[l2 + x] = t ^ mn[l + x];
            mx[l2 + x] = t ^ mx[l + x];
        }
        return;
    }
    range(x, t) {
        ans[k - 1][x] = min(ans[k - 1][x], mn[l2 + x] - mx[l + x]);
        int x2 = x ^t;
        ans[k - 1][x2] = min(ans[k - 1][x2], (mn[l + x] ^ t) - (t ^ mx[l2 + x]));
        mn[l2 + x] ^= t;
        swap(mx[l2 + x], mx[l + x]);
        mx[l2 + x] ^= t;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    range(i, n) {
        int x;
        cin >> x;
        has[x] = true;
    }
    range(i, (1 << k)) {
        mx[i] = mn[i] = -1;
    }
    range(bt, K) {
        range(x, 1 << K) ans[bt][x] = INFi;
    }
    rec(0, k);
    range(bt, k - 1) {
        range(x, 1 << (bt + 1)) {
            ans[bt + 1][x ^ (1 << (bt + 1))] = min(ans[bt + 1][x ^ (1 << (bt + 1))], ans[bt][x]);
            ans[bt + 1][x] = min(ans[bt + 1][x], ans[bt][x]);
        }
    }
    range(i, 1 << k) {
        cout << ans[k - 1][i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}