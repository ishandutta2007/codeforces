#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> v;
    for (int i = 1; i < n-1; i++) {
        if (a[i] > a[i-1] && a[i] > a[i+1])
            v.push_back(i);
    }
    const int M = 1e9;
    int ans = 0;
     

    for (int i = 0; i < sz(v); i++) {
        if (i == sz(v) - 1 || v[i+1] - v[i] != 2) {
            ans++;
            a[v[i]] = max(a[v[i]-1], a[v[i]+1]);
        } else {
            ans++;
            a[v[i]+1] = max(a[v[i]], a[v[i]+2]);
            i++;
        }
    }
    cout << ans << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}