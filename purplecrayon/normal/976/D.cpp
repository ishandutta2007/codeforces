#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& d : a) cin >> d;

    vector<ar<int, 2>> ans;

    int l=0, r=n-1, c=1, v=a[n-1]+1;
    while (l <= r) {
        for (int i = 0; i < a[l]-(l?a[l-1]:0); i++) {
            for (int j = c+1; j <= v; j++)
                ans.push_back({c, j});
            c++;
        }
        l++, r--;
        v = a[r]+1;
    }
    cout << sz(ans) << '\n';
    for (auto c : ans) cout << c[0] << ' ' << c[1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}