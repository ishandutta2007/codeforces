#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);

const int inf = 1e9 + 7;
const int N = 1e5 + 3;

void run() {
    int n, m, k;
    cin >> n >> m >> k; ++k;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = (s[j] == '*');
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int le = 0, ri = 0;
            while (i - le >= 0 && j - le >= 0 && a[i - le][j - le])
                ++le;
            while (i - ri >= 0 && j + ri < m && a[i - ri][j + ri])
                ++ri;
            if (min(le, ri) >= k) {
                for (int q = 0; q < min(le, ri); ++q)
                    b[i - q][j - q] = 1, b[i - q][j + q] = 1;
            }
        }
    }
    bool good = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] && !b[i][j]) good = false;
    cout << (good ? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}