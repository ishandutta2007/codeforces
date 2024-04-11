#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] -= x;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] += x;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int L = 0, R = n-1; L < R; ) {
        if (a[L] + a[R] < 0) L++;
        else {
            ans++;
            L++, R--;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}