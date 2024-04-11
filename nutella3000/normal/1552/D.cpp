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

bool inter(pii v1, pii v2) {
    if (v1.se < v1.fi) swap(v1.fi, v1.se);
    if (v2.se < v2.fi) swap(v2.fi, v2.se);
    int q1 = (v1.fi < v2.fi && v1.se > v2.fi);
    int q2 = (v1.fi < v2.se && v1.se > v2.se);
    if (q1 && q2) return false;
    if (!q1 && !q2) return false;
    return true;
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    set<int> sum;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int q = 0;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) q += a[i];
        }
        if (sum.count(q)) {
            cout << "YES" << endl;
            return;
        }
        sum.insert(q);
    }
    cout << "NO" << endl;
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