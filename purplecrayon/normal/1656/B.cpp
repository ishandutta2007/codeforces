#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    set<ll> s; for (auto& x : a) s.insert(x);
    for (int x : a) if (s.count(x + k)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}