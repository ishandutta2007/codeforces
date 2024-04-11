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

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return make_pair(a[i], i) < make_pair(a[j], j);
    });
    int last = 0;
    vector<bool> us(n);
    int cur = n;
    for (auto &j : ord) {
        if (last == a[j]) {
            cur--;
            continue;
        }
        if (k < cur) break;
        ll t = min(k / cur, (ll) a[j] - last);
        last += t;
        k -= t * cur;
        if (last == a[j]) {
            cur--;
        } else {
            break;
        }
    }
    vector<int> aa;
    vector<int> bb;
    range(i, n) {
        if (a[i] <= last) continue;
        if (aa.size() < k) {
            aa.push_back(i);
        } else {
            bb.push_back(i);
        }
    }
    if (cur == 0 && k) {
        cout << "-1\n";
        return;
    }
    for(auto &i : bb) cout << i + 1 << ' ';
    for(auto &i : aa) if (a[i] - last - 1 != 0) cout << i + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}