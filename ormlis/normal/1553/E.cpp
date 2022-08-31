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
const int maxN = 2e5 + 5;
const int md = 31607;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector<int> cnt(n);
    range(i, n) {
        cin >> p[i];
        p[i]--;
        cnt[(i - p[i] + n) % n]++;
    }
    vector<int> ans;
    auto check = [&] (int k) {
        vector<int> to(n);
        range(i, n) {
            to[i] = (p[i] + k) % n;
        }
        int cyc = 0;
        vector<bool> us(n);
        range(i, n) {
            if (us[i]) continue;
            int x = i;
            while(!us[x]) {
                us[x] = true;
                x = to[x];
            }
            cyc++;
        }
        if (n - cyc <= m) {
            ans.push_back(k);
        }
    };
    range(i, n) {
        if (cnt[i] < n - m * 2) continue;
        check(i);
    }
    cout << ans.size() << ' ';
    for(auto &x : ans) cout << x << ' ';
    cout << '\n';
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