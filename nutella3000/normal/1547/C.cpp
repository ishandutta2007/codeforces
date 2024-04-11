#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

bool run() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m), c;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int id = 0;
    for (int i = 0; i < n; ++i) {
        while (id < m && b[id] < a[i]) c.pb(b[id++]);
        c.pb(a[i]);
    }
    while (id < m) c.pb(b[id++]);
    
    int q = 0;
    for (int i = 0; i < n + m; ++i) {
        if (c[i] > k + q) return false;
        if (c[i] == 0) ++q;
    }

    for (int i : c)
        cout << i << " ";
    cout << endl;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t = 1;
    cin >> t;
    while (t--) {
        if (!run()) cout << -1 << endl;
    }
}