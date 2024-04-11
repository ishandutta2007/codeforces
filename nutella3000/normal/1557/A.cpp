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
 
const int inf = 1e15 + 3;
const int max_n = 2e5 + 3;

void run() {
    int n;
    cin >> n;
    vector<int> a(n), pr(n + 1), sf(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n; ++i)
        pr[i + 1] = pr[i] + a[i];
    for (int i = n - 1; i >= 0; --i)
        sf[i] = sf[i + 1] + a[i];

    double res = -inf;
    for (int i = 1; i < n; ++i) {
        chkmax(res, (double)pr[i] / i + (double)sf[i] / (n - i));
    }
    cout << res << endl;
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
        run();
    }
}