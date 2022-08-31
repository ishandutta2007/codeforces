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


void solve() {
    int n, q; cin >> n >> q;
    vector<int> cnt(n);
    string s; cin >> s;
    range(i, n) {
        if (i >= 2) cnt[i] = cnt[i - 2];
        if (s[i] == '+') cnt[i]++;
    }
    map<int, set<int>> mp;
    vector<int> psum(n);
    range(i, n) {
        int x = int(s[i] == '+') ^ (i & 1);
        if (x == 0) x--;
        psum[i] = x;
        if (i) psum[i] += psum[i - 1];
        mp[-x + 2 * psum[i]].insert(i);
    }
    auto solve = [&] (int l, int r) {
        int cur = psum[r] - (l == 0 ? 0 : psum[l - 1]);
        cur -= psum[r] * 2;
        auto it = mp[-cur].lower_bound(l);
        assert(it != mp[-cur].end());
        return *it;
    };
    range(_, q) {
        int l, r; cin >> l >> r;
        if ((r - l + 1) % 2) {
            cout << "1\n";
            cout << solve(l - 1, r - 1) + 1 << '\n';
            continue;
        }
        int a = cnt[r - 1] - (l == 1 ? 0 : cnt[l - 2]);
        int b = cnt[r - 2] - (l <= 2 ? 0 : cnt[l - 3]);
        if (a == b) {
            cout << "0\n";
        } else {
            cout << "2\n";
            cout << r << " " << solve(l - 1, r - 2) + 1 << '\n';
        }
    }
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