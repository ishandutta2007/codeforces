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
const int max_n = 2e5 + 3, log_n = 20;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> sp(n, vector<int>(log_n));
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        sp[i][0] = gcd(a[i], a[(i + 1) % n]);
    for (int i = 1; i < log_n; ++i) {
        for (int j = 0; j < n; ++j) {
            sp[j][i] = gcd(sp[j][i - 1], sp[(j + (1 << (i - 1))) % n][i - 1]);
        }
    }
    int G = sp[0][log_n - 1], res = 0;

    for (int l = 0; l < n; ++l) {
        int v = l, vg = a[l];
        for (int k = log_n - 1; k >= 0; --k) {
            int nvg = gcd(vg, sp[v][k]);
            if (nvg != G) vg = nvg, v = (v + (1 << k)) % n;
        }
        if (vg != G) ++v;
        chkmax(res, (v + n - l) % n);
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