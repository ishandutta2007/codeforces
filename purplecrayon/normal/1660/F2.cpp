#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// you need - >= +
// and (-) % 3 - (p_-)  == (+) % 3

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    // c_m - p_m >= c_p - p_p
    // c_m - c_p >= p_m - p_p
    
    int T = 0;
    oset<pair<int, int>> o[3];
    o[0].insert({0, T++});
    int m = 0, p = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') m++;
        else p++;

        ans += o[((m - p) % 3 + 3) % 3].order_of_key({m - p, T+1});

        o[((m - p) % 3 + 3) % 3].insert({m - p, T++});
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}