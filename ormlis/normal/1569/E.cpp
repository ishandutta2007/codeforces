#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int to[6][32];
int k;
map<int, int> have[33];
int stA[35];

void rec(int i, int n, int S, int mask2, int hc) {
    if (n == 1) {
        have[to[i][0]][hc] = mask2;
        return;
    }
    range(mask, 1 << (n / 2)) {
        int hc2 = hc;
        range(j, n / 2) {
            if (mask & (1 << j)) {
                to[i + 1][j] = to[i][j * 2 + 1];
                hc2 = add(hc2, mul(to[i][j * 2], stA[n + 1]));
            } else {
                to[i + 1][j] = to[i][j * 2];
                hc2 = add(hc2, mul(to[i][j * 2 + 1], stA[n + 1]));
            }
        }
        rec(i + 1, n / 2, S + (n / 2), mask2 | (mask << S), hc2);
    }
}

int ans[33];

void restore(int i, int n, int mask) {
    if (n == 1) {
        return;
    }
    range(j, n / 2) {
        if (mask & (1 << j)) {
            to[i + 1][j] = to[i][j * 2 + 1];
            ans[to[i][j * 2]] = n + 1;
        } else {
            to[i + 1][j] = to[i][j * 2];
            ans[to[i][j * 2 + 1]] = n + 1;
        }
    }
    mask >>= n / 2;
    restore(i + 1, n / 2, mask);
}

void print_ans(int a, int b, int mask1, int mask2, int wn) {
    if (wn == 0) {
        ans[a] = 1;
        ans[b] = 2;
    } else {
        ans[b] = 1;
        ans[a] = 2;
    }
    range(i, 1 << (k - 1)) to[0][i] = i + 1;
    restore(0, 1 << (k - 1), mask1);

    range(i, 1 << (k - 1)) to[0][i] = (1 << (k - 1)) + i + 1;
    restore(0, 1 << (k - 1), mask2);

    for(int i = 1; i <= (1 << k); ++i) {
        cout << ans[i] << ' ';
    }
    exit(0);
}

void solve() {
    int A, h;
    cin >> k >> A >> h;
    stA[0] = 1;
    for(int i = 1; i < 35; ++i) {
        stA[i] = mul(stA[i - 1], A);
    }
    int n = 1 << k;
    range(i, n / 2) to[0][i] = i + 1;
    rec(0, n / 2, 0, 0, 0);
    range(i, n / 2) to[0][i] = i + n / 2 + 1;
    rec(0, n / 2, 0, 0, 0);
    for (int a = 1; a <= n / 2; ++a)
        for (int b = n / 2 + 1; b <= n; ++b) {
            for (auto &[h1, mask1] : have[a]) {
                {
                    int h3 = h1;
                    h3 = add(h3, mul(a, A));
                    h3 = add(h3, mul(b, stA[2]));
                    h3 = sub(h, h3);
                    if (have[b].count(h3)) {
                        print_ans(a, b, mask1, have[b][h3], 0);
                    }
                }
                {
                    int h3 = h1;
                    h3 = add(h3, mul(a, stA[2]));
                    h3 = add(h3, mul(b, A));
                    h3 = sub(h, h3);
                    if (have[b].count(h3)) {
                        print_ans(a, b, mask1, have[b][h3], 1);
                    }
                }
            }
        }
    cout << "-1\n";
    return;
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