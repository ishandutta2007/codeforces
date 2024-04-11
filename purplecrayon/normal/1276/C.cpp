#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;

    map<int, int> mp;
    for (auto c : a) mp[c]++;

    vector<vector<int>> v(n+1);
    for (auto c : mp) v[c.second].push_back(c.first);
    vector<int> ps(n+1);
    for (int i = 0; i <= n; i++) {
        ps[i] = sz(v[i]);
    }
    for (int i = n-1; i >= 0; i--) ps[i] += ps[i+1];

    ll x=0, p=0, q=0;
    for (int i = 1; i <= n; i++) {
        x += ps[i]; ll j = x/i;
        if (p*q < i*j && i <= j) p = i, q = j;
    }
    vector<vector<int>> ans(p, vector<int>(q));
    int i = 0, j = 0;
    for (int k = n; k >= 1; k--) {
        for (auto c : v[k]) for (int l = 0; l < min<int>(k, p); l++) {
            if (ans[i][j]) i++, i %= p;
            if (!ans[i][j]) ans[i][j] = c;
            i++, j++; i %= p, j %= q;
        }
    }

    cout << p*q << '\n' << p << ' ' << q << '\n';
    for (auto& r : ans) { for (auto& c : r) cout << c << ' '; cout << '\n'; }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}