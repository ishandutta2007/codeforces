#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    ar<ll, 2> sum; sum.fill(0);
    for (int i = 0; i < n; i++) sum[i % 2] += a[i];
    int M = min_element(sum.begin(), sum.end()) - sum.begin();
    for (int i = 0; i < n; i++) {
        if (i % 2 == M) cout << 1 << ' ';
        else cout << a[i] << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}