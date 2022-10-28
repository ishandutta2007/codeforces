#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int b = 31 - __builtin_clz(n - 1);
    vector<int> ans(n); iota(ans.begin(), ans.end(), 0);
    swap(ans[0], ans[(1 << b) - 1]);
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}