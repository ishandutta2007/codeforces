#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    reverse(a.begin(), a.end());
    int p = -1, ans = 0;
    for (int c : a) if (c > p) {
        ans++;
        p = c;
    }
    cout << ans-1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}