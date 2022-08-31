#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for (int i = n; i >= 2; i -= 2) {
        swap(ans[i-1], ans[i-2]);
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}