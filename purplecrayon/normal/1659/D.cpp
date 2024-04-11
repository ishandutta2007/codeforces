#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 1);

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (cur == i) {
            if (x) a[x] = 0;
            else a[i] = 0;
        } else {
            if (a[i]) a[x] = 0;
            else a[x + i] = 0;
        }
        if (!a[i]) cur++;
    }

    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}