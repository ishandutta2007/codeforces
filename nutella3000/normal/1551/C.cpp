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

const int inf = 2e9 + 3;
const int max_n = 4e5 + 3;

void run() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i].resize(5, -size(s));
        for (int j = 0; j < size(s); ++j) {
            a[i][s[j] - 'a'] += 2;
        }
    }
    int res = 0;
    for (int i = 0; i < 5; ++i) {
        vector<int> b(n);
        for (int j = 0; j < n; ++j)
            b[j] = a[j][i];
        sort(all(b));
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += b[i];
            if (sum > 0) chkmax(res, n - i);
        }
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