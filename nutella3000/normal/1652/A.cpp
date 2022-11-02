#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define siz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb emplace_back


void run() {
    int n; cin >> n;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        if (v > mx1) mx2 = mx1, mx1 = v;
        else if (v > mx2) mx2 = v;
    }
    cout << mx1+mx2 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}