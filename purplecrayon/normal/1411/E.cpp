#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

//???????+-

const int L = 60;
ll cnt[L];

void solve() {
    int n; ll T; cin >> n >> T;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (i == n-2) {
            T += 1ll << (s[i] - 'a');
            continue;
        }
        if (i == n-1) {
            T -= 1ll << (s[i] - 'a');
            continue;
        }
        T -= 1ll << (s[i] - 'a');
        cnt[s[i]-'a'+1]++;
    }
    if (T > 0) {
        cout << "No\n";
        return;
    }
    T *= -1;

    for (int i = L-1; i >= 0; i--) {
        ll take = min(cnt[i], T>>i);
        T -= take << i;
    }
    if (T) cout << "No\n";
    else cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}