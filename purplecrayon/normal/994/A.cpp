#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    bool has[10]={};
    vector<int> a(n); for (auto& c : a) cin >> c;
    while (m--) { int c; cin >> c; has[c] = 1; }
    for (auto c : a) if (has[c]) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}