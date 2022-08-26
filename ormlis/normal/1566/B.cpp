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
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    string s; cin >> s;
    ar<int, 2> cnt = {0, 0};
    for(auto &c : s) cnt[c - '0']++;
    if (cnt[0] == 0) {
        cout << "0\n";
        return;
    }
    if (cnt[1] == 0) {
        cout << "1\n";
        return;
    }
    int n = s.size();
    int cnt0 = 0;
    range(i, n) {
        if (s[i] == '0') {
            if (i == 0 || s[i - 1] == '1') {
                cnt0++;
            }
        }
    }
    cnt0 = min(cnt0, 2);
    cout << cnt0 << '\n';
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