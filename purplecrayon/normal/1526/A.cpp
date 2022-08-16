#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(2*n); for (auto& it : a) cin >> it;
    sort(a.begin(), a.end());

    for (int i = 0; i < 2*n; i++) {
        if (i&1) cout << a[i/2] << ' ';
        else cout << a[n + i/2] << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}