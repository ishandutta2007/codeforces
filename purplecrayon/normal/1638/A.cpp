#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    int pos = -1;
    for (int i = 0; i < n; i++) if (a[i] != i) {
        pos = i;
        break;
    }
    if (pos != -1) {
        int l = pos;
        int r = -1;
        for (int i = 0; i < n; i++) if (a[i] == pos)
            r = i;

        reverse(a.begin() + l, a.begin() + r + 1);
    }
    for (int x : a) cout << x+1 << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}