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
typedef __int128 i128;

const int INFi = 1e9 + 5;
const int maxN = 1e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> a, b;
    range(i, n) {
        if (s[i] == '0') a.push_back(i);
        else b.push_back(i);
    }
    if (a.empty() || b.empty()) {
        cout << "tokitsukaze\n";
        return;
    }
    if (a.back() - a.front() <= k - 1 || b.back() - b.front() <= k - 1) {
        cout << "tokitsukaze\n";
        return;
    }
    auto check = [&] (int l, vector<int> &v) {
        int r = l + k - 1;
        if (v.front() < l && v.back() > r) return true;
        if (v.front() < l) {
            int j = lower_bound(all(v), l) - v.begin();
            j--;
            if (v[j] - v[0] >= k) return true;
        } else if (v.back() > r) {
            int j = upper_bound(all(v), r) - v.begin();
            if (v.back() - v[j] >= k) return true;
        }
        return false;
    };
    range(l, n - k + 1) {
        if (check(l, a) || check(l, b)) {
            cout << "once again\n";
            return;
        }
    }
    cout << "quailty\n";
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