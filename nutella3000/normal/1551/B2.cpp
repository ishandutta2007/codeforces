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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> id(n + 1);
    for (int i = 0; i < n; ++i)
        id[a[i]].pb(i);
    vector<int> res(n);

    int col = 1;
    for (int i = 0; i <= n; ++i) {
        int c = 0;
        for (int j : id[i]) {
            res[j] = col++;
            if (col == k + 1) col = 1;
            ++c;
            if (c == k) break;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j : id[i]) {
            if (col == 1) break;
            res[j] = 0;
            --col;
        }
    }
    for (int i : res)
        cout << i << " ";
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