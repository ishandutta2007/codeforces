#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

bool is_pal(int x) {
    string s = to_string(x);
    string t = s; reverse(t.begin(), t.end());
    return s == t;
}
void solve() {
    const int M = 1.5e6;
    int p, q; cin >> p >> q;

    int ans = -1;
    int one = 0, two = 0;

    vector<bool> is_prime(M, 1);
    is_prime[1] = 0;
    for (int i = 2; i < M; i++) if (is_prime[i]) {
        for (int j = 2*i; j < M; j += i) is_prime[j] = 0;
    }
    for (int i = 1; i < M; i++) {
        one += is_prime[i];
        two += is_pal(i);
        // one * q <= two * p
        if ((long long) one * q <= (long long) two * p) {
            ans = i;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}