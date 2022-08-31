#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    const int A = 26;
    vector<int> dp(A);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < A; j++) { // best with this char
            int best = 0, run = 0;
            for (int k = 0; k < sz(s); k++) {
                if (s[k] == j + 'a') run++;
                else best = max(best, run), run = 0;
            }
            best = max(best, run);
            if (dp[j] == 0) {
                dp[j] = best;
                continue;
            }
            if (best == sz(s)) {
                dp[j] += best * (dp[j] + 1);
                continue;
            }
            int one = 0, two = sz(s) - 1;
            while (s[one] == j + 'a') one++;
            while (s[two] == j + 'a') two--;
            dp[j] = max(best, one + sz(s) - 1 - two + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}