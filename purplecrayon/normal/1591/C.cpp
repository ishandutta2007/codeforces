#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> one, two;
    while (n--) {
        int x; cin >> x;
        if (x < 0) one.push_back(-x);
        else if (x > 0) two.push_back(x);
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    int M = 0;
    if (sz(one)) M = max(M, one.back());
    if (sz(two)) M = max(M, two.back());

    ll ans = 0;
    while (sz(one)) {
        ans += one.back();
        int K = min(sz(one), k);
        for (int i = 0; i < K; i++) one.pop_back();
    }
    while (sz(two)) {
        ans += two.back();
        int K = min(sz(two), k);
        for (int i = 0; i < K; i++) two.pop_back();
    }
    ans *= 2;
    ans -= M;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}