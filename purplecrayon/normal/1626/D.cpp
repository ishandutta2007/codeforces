#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = n + 1;
    for (int L = 1; L <= 2 * n; L *= 2) {
        for (int R = 1; R <= 2 * n; R *= 2) {
            for (int M = 1; M <= 2 * n; M *= 2) {
                // one: everything < a[L-1]
                // three: everything > a[n-R]
                // two: everything else

                int one = -1;
                if (L > n) one = n;
                else {
                    one = lower_bound(a.begin(), a.end(), a[L-1]) - a.begin();
                    if (L == n || a[L-1] != a[L]) one = L;
                }

                int three = -1;
                if (R > n) three = n;
                else { 
                    three = n - (upper_bound(a.begin(), a.end(), a[n-R]) - a.begin());
                    if (R == n || a[n-R-1] != a[n-R]) three = R;
                }

                three = min(three, n - one);

                int two = n - one - three;
                if (two > M) continue;


                assert(0 <= one && one <= L);
                assert(0 <= two && two <= M);
                assert(0 <= three && three <= R);

                ans = min(ans, L - one + M - two + R - three);
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}