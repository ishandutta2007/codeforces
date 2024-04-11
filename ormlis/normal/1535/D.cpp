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
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int k; cin >> k;
    int n = 1 << k;
    vector<int> sum(n * 2);
    vector<int> to(n);
    vector<int> from(n * 2);
    range(i, n) sum[i + n] = 1;
    int j = 0;
    string s; cin >> s;
    for(int i = n / 2; i >= 1; i >>= 1) {
        range(e, i) {
            to[j] = i + e;
            from[i + e] = j;
            char x = s[j++];
            if (x == '?' || x == '0') {
                sum[i+e] += sum[(i+e)<<1];
            }
            if (x == '?' || x == '1') {
                sum[i+e] += sum[(i+e)<<1|1];
            }
        }
    }
    auto upd = [&] (int p) {
        while(p >= 1) {
            char x = s[from[p]];
            sum[p] = 0;
            if (x == '?' || x == '0') {
                sum[p] += sum[p << 1];
            }
            if (x == '?' || x == '1') {
                sum[p] += sum[p << 1 | 1];
            }
            p >>= 1;
        }
    };
    int q; cin >> q;
    range(_, q) {
        int p;
        char c; cin >> p >> c;
        s[p - 1] = c;
        upd(to[p - 1]);
        cout << sum[1] << '\n';
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