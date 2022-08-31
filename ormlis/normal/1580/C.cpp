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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    range(i, n) cin >> x[i] >> y[i];
    vector<int> ans(m);
    const int K = 500;
    vector<vector<int>> to(n);
    vector<vector<int>> change(K, vector<int>(K));
    vector<int> was(n);
    int current = 0;
    range(i, m) {
        int op, k;
        cin >> op >> k;
        k--;
        if (x[k] + y[k] >= K) {
            to[k].push_back(i);
        } else {
            if (op == 1) {
                current++;
                int d = i + x[k];
                int c = x[k] + y[k];
                was[k] = i % c;
                change[c][d % c]++;
                change[c][was[k]]--;
            } else {
                int t = was[k];
                int c = x[k] + y[k];
                int w = (i - t) % c;
                change[c][(was[k] + x[k]) % c]--;
                change[c][was[k]]++;
                if (w == 0) {
                    current--;
                }
                if (w > x[k]) {
                    current--;
                }
            }
        }
        for(int c = 1; c < K; ++c) {
            current += change[c][i % c];
        }
        ans[i] = current;
    }
    vector<int> add(m + 1);
    range(i, n) {
        if (to[i].size() % 2 == 1) {
            to[i].push_back(m);
        }
        for(int j = 1; j < (int)to[i].size(); j += 2) {
            int a = to[i][j - 1];
            int b = to[i][j];
            int xx = x[i];
            int yy = y[i];
            int d = xx + yy;
            for(int r = a + d, mid = a + xx; mid < b; r += d, mid += d) {
                add[mid]++;
                add[min(b, r)]--;
            }
        }
    }
    int c = 0;
    range(i, m) {
        c += add[i];
        cout << c + ans[i] << '\n';
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