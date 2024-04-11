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
const int LG = 20;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n * 2 - 1);
    set<int> l, r;
    vector<int> b(n);
    range(i, n) cin >> b[i];
    a[0] = b[0];
    int mid = a[0];
    for(int i = 1; i < n; ++i) {
        int x = b[i];
        if (x == mid) {
            a[i * 2 - 1] = -INFi;
            a[i * 2] = INFi;
            continue;
        }
        if (x < mid) {
            if (!l.empty() && (*l.rbegin()) == x) {
                a[i * 2 - 1] = a[i * 2] = -INFi;
                r.insert(mid);
                l.erase(x);
                mid = x;
                continue;
            }
            if (!l.empty() && (*l.rbegin()) > x) {
                cout << "NO\n";
                return;
            }
            r.insert(mid);
            a[i * 2 - 1] = x;
            a[i * 2] = -INFi;
            mid = x;
        } else {
            if (!r.empty() && (*r.begin()) == x) {
                a[i * 2 - 1] = a[i * 2] = INFi;
                l.insert(mid);
                r.erase(x);
                mid = x;
                continue;
            }
            if (!r.empty() && (*r.begin()) < x) {
                cout << "NO\n";
                return;
            }
            l.insert(mid);
            a[i * 2 - 1] = x;
            a[i * 2] = INFi;
            mid = x;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}