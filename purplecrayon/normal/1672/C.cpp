#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<bool> pre(n, true), suf(n, true);
    for (int i = 0; i < n; i++) {
        if (i && a[i] == a[i-1]) pre[i] = false;
        if (i) pre[i] = pre[i] && pre[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1 && a[i] == a[i+1]) suf[i] = false;
        if (i < n-1) suf[i] = suf[i] && suf[i+1];
    }
    if (pre[n-1]) {
        cout << 0 << '\n';
        return;
    }
    int l = 0, r = n-1;
    while (a[l] != a[l+1]) l++;
    while (a[r] != a[r-1]) r--;
    int len = r - l + 1;
    if (len == 2) {
        cout << 0 << '\n';
        return;
    }
    cout << max(1, len - 3) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}