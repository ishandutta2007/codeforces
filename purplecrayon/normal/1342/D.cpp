#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

vector<int> pr[MAXN];
int ceil_div(int x, int y){ return (x+y-1)/y; }
void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<int> c(k); for (auto& it : c) cin >> it;
    sort(a.rbegin(), a.rend());
    int ans = 0, ptr = 0;
    for (int i = k-1; i >= 0; i--) {
        for (; ptr < n && a[ptr] == i+1; ptr++);
        //ceil_div(ptr, c[i])
        int cur = ceil_div(ptr, c[i]);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        pr[i%ans].push_back(a[i]);
    }
    for (int i = 0; i < ans; i++) {
        cout << sz(pr[i]) << ' ';
        for (auto c : pr[i]) cout << c << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}