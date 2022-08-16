#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 998244353;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x; 
    vector<int> p(n); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] > a[y]; });
    ll one = 0, two = 1;
    vector<int> pos(k);
    for (int i = 0; i < k; i++) {
        pos[i] = p[i];
        one += a[p[i]];
    }
    sort(pos.begin(), pos.end());
    for (int i = 1; i < k; i++) two *= pos[i] - pos[i-1], two %= MOD;
    cout << one << ' ' << two << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}