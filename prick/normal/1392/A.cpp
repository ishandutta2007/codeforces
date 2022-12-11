#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }
    if (sz(cnt) == 1) {
        cout << n << '\n';
    } else {
        cout << 1 << '\n';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}