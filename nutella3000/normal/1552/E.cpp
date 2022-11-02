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
    int n, k;
    cin >> n >> k;
    int m = (n + k - 2) / (k - 1);
    vector<vector<int>> x(n);
    for (int i = 0; i < n * k; ++i) {
        int v;
        cin >> v;
        x[v - 1].pb(i);
    }
    vector<pii> res(n);
    vector<bool> used(n);

    vector<int> id(n);
    iota(all(id), 0);
    for (int i = 1; i < k; ++i) {
        sort(all(id), [&](int v1, int v2) { return x[v1][i] < x[v2][i]; });
        int cnt = 0;
        for (int j : id) {
            if (used[j]) continue;
            res[j] = mp(x[j][i - 1], x[j][i]);
            used[j] = true;
            ++cnt;
            if (cnt == m) break;
        }
    }
    for (auto i : res)
        cout << i.fi + 1 << " " << i.se + 1 << endl;
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