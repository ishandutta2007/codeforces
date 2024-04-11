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
 
const int inf = 1e15 + 3;
const int max_n = 2e5 + 3;

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), id(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    iota(all(id), 0);
    sort(all(id), [&](int v1, int v2) { return a[v1] < a[v2]; });
    vector<int> revid(n);
    for (int i = 0; i < n; ++i)
        revid[id[i]] = i;
    for (int i = 1; i < n; ++i) {
        if (revid[i - 1] != revid[i] - 1) --k;
    }
    cout << (k <= 0 ? "No" : "Yes") << endl;
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