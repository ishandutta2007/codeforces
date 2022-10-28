#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e3+10, MOD = 1e9+7;
 
void solve() {
    int n; cin >> n; n *= 2;
    vector<int> a(n); for (auto& c : a) cin >> c, --c;

    int ans = MOD;
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << '\n';
        return;
    }
    for (int rep = 0; rep < 2; rep++) {
        const int MAGIC = 10;

        vector<int> p = a;

        auto one = [&]() { for (int i = 0; i < n; i += 2) swap(p[i], p[i+1]); };
        auto two = [&]() { for (int i = 0; i < n/2; i++) swap(p[i], p[i+n/2]); };

        bool b = rep;
        for (int i = 1; i <= 2*n+MAGIC; i++, b ^= 1) {
            if (b) one();
            else two();
            if (is_sorted(p.begin(), p.end())) {
                ans = min(ans, i);
                break;
            }
        }
    }
    cout << (ans == MOD ? -1 : ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}