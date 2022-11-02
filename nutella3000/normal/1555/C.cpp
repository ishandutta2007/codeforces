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

const int mod = 1e9 + 7;
const int max_n = 1e5 + 3;

const int inf = 2e9 + 3;

void run() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 1; i < n; ++i)
        b[i] += b[i - 1];
    for (int i = n - 2; i >= 0; --i)
        a[i] += a[i + 1];

    int res = inf;
    for (int i = 0; i < n; ++i)
        chkmin(res, max(i + 1 != n ? a[i + 1] : 0, i ? b[i - 1] : 0));
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