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

const int inf = 2e9 + 3, mod = 1e9 + 7;
const int max_n = 1e3 + 3;

int n, m;
int a[max_n][max_n], sum[max_n], sum2[max_n];

void run() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            sum2[i] += a[i][j] * a[i][j];
        }
    }
    int x = (sum[n - 1] - sum[0]) / (n - 1), ad;
    int r1 = -1, r2 = -1;
    for (int i = 1; i < n; ++i) {
        if (sum[0] + i * x != sum[i]) r1 = i, ad = sum[0] + i * x - sum[i];
    }
    int y = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (i + 1 < r1 || i - 1 > r1) {
            y = (sum2[i + 1] + sum2[i - 1] - 2 * sum2[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int c = sum2[r1] - a[r1][i] * a[r1][i] + (a[r1][i] + ad) * (a[r1][i] + ad);
        if (sum2[r1 + 1] + sum2[r1 - 1] - 2 * c == y) {
            r2 = i;
        }
    }
    cout << r1 << " " << a[r1][r2] + ad << endl;
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