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

const int max_n = 2e5 + 3, log_n = 20;


int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int g[max_n][log_n];

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 1; --i) {
        a[i] -= a[i - 1];
        g[i][0] = a[i];
    }
    for (int i = 1; i < log_n; ++i) {
        for (int j = 1; j + (1 << (i - 1)) < n; ++j) {
            g[j][i] = gcd(g[j][i - 1], g[j + (1 << (i - 1))][i - 1]);
        }
    }
    int res = 0;
    for (int l = 1; l < n; ++l) {
        int v = l, num = 0;
        for (int k = log_n - 1; k >= 0; --k) {
            if (v + (1 << k) > n) continue;
            int nnum = gcd(num, g[v][k]);
            if (abs(nnum) != 1) {
                num = nnum;
                v += (1 << k);
            }
        }
        chkmax(res, v - l);
    }
    cout << res + 1 << endl;
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