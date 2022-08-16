#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

bool is_prime(int x) {
    for (int i = 2; i*i <= x; i++) if (x % i == 0) return 0;
    return 1;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    for (int i = n; i >= 0; i--) {
        int sum = 0;
        vector<int> ans; ans.reserve(n);
        for (int j = 0; j < n; j++) if (j != i) {
            sum += a[j];
            ans.push_back(j);
        }
        if (!is_prime(sum)) {
            cout << sz(ans) << '\n';
            for (auto c : ans) cout << c+1 << ' '; cout << '\n';
            return;
        }
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}