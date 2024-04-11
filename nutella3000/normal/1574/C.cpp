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
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 2e18 + 3;
const int max_n = 2e6 + 3;

void run() {
    int n, m, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        int id = lower_bound(all(a), x) - a.begin();
        int res = inf;
        if (id < n) res = max(0ll, y - sum + a[id]);
        if (id) chkmin(res, max(0ll, y - sum + a[id - 1]) + x - a[id - 1]);
        cout << res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}