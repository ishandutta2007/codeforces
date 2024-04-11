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
const int maxN = 1e3 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

string s;
int pos = 0;
vector<int> b;
vector<int> a;

void rec(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    rec(l, m);
    rec(m, r);
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (s[pos++] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < m) b[k++] = a[i++];
    while (j < r) b[k++] = a[j++];
    for(int p = l; p < r; ++p) a[p] = b[p];
}

void solve() {
    cin >> s;
    b.resize(16);
    a.resize(16);
    iota(all(a), 0);
    rec(0, 16);
    range(i, 16) b[a[i]] = i + 1;
    cout << "16\n";
    for(auto &x : b) cout << x << ' ';
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