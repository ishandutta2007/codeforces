#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> ans;
    for (int i = n-2; i >= 1; i--) ans.push_back(i);
    ans.push_back(n-1), ans.push_back(n);
    if (n % 2) {
        swap(ans[0], ans[1]);
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