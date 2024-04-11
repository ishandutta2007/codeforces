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
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n - 1);
    vector<vector<int>> cnt(m, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j)
            ++cnt[j][a[i][j] - 'a'];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
        for (int j = 0; j < m; ++j)
            --cnt[j][b[i][j] - 'a'];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j)
            if (cnt[i][j]) cout << char('a' + j);
    }
    cout << endl;
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