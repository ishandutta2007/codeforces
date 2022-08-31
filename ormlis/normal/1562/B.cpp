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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }
bool pr[maxN];
void init() {
    pr[1] = true;
    for(int i = 2; i < maxN; ++i) {
        if (pr[i]) continue;
        for(int j = i * 2; j < maxN; j += i) pr[j] = true;
    }
}

void solve() {
    int k; cin >> k;
    string s; cin >> s;
    bool ok = false;
    for(int ans = 1; ans <= (int)s.size(); ++ans) {
        function<void(int, int, int)> rec = [&] (int i, int c, int x) {
            if (ok) return;
            if (i == (int)s.size()) {
                if (c < ans) return;
                if (!pr[x]) return;
                ok = true;
                cout << c << '\n' << x << '\n';
                return;
            }
            rec(i + 1, c, x);
            if (c < ans) {
                rec(i + 1, c + 1, x * 10 + (s[i] - '0'));
            }
        };
        rec(0, 0, 0);
        if (ok) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    init();
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}