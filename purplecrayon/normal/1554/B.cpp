#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& c : a) cin >> c;


    //n*n - n*k
    //n*(n-k)

    auto get = [&](int i, int j) {
        return ll(i+1)*ll(j+1)-ll(k)*ll(a[i]|a[j]);
    };

    ll ans = get(0, 1);
    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            ll poss = ll(i+1)*ll(j+1);
            if (poss < ans) break;
            ans = max(ans, get(i, j));
        } 
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}