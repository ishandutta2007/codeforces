#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const int B = 31;

int m = 0;
int nxt[N * B][2];
int best[N * B][2][2];

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    for (int i = 0; i <= n * B; i++) {
        for (int j = 0; j < 2; j++) {
            nxt[i][j] = -1;
            for (int k = 0; k < 2; k++) {
                best[i][j][k] = 0;
            }
        }
    }
    vector<int> dp(n);
    m = 1;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = 1;
        int x = a[i] ^ i;
        int c = 0;
        for (int j = B-1; j >= 0; j--) {
            for (int one = 0; one < 2; one++) {
                for (int two = 0; two < 2; two++) {
                    int three = (a[i] >> j) & 1;
                    int four = (i >> j) & 1;
                    // three ^ two < one ^ four
                    if ((three ^ two) < (one ^ four) && ((one ^ two ^ three ^ four) != 0)) {
                        dp[i] = max(dp[i], 1 + best[c][one][two]);
                    }
                }
            }
            if (nxt[c][(x >> j) & 1] == -1) nxt[c][(x >> j) & 1] = m++;
            c = nxt[c][(x >> j) & 1];
        }
        // insert (a[i], i)
        c = 0;
        for (int j = B-1; j >= 0; j--) {
            int one = (a[i] >> j) & 1;
            int two = (i >> j) & 1;
            best[c][one][two] = max(best[c][one][two], dp[i]);
            if (nxt[c][(x >> j) & 1] == -1) nxt[c][(x >> j) & 1] = m++;
            c = nxt[c][(x >> j) & 1];
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}