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
const int max_n = 2e5 + 3;

void run() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    int id = 0;
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
            if (a[id][j] < a[i][j]) ++c;
        }
        if (c < 3) id = i;
    }
    for (int i = 0; i < n; ++i) {
        if (i == id) continue;
        int c = 0;
        for (int j = 0; j < 5; ++j)
            if (a[id][j] < a[i][j]) ++c;
        if (c < 3) {
            cout << -1 << endl;
            return;
        }
    }
    cout << id + 1 << endl;
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