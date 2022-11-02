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
    int n, k;
    cin >> n >> k;
    vector<bool> used(2 * n + 1);
    vector<pii> st(k);
    for (int i = 0; i < k; ++i) {
        cin >> st[i].fi >> st[i].se;
        used[st[i].fi] = used[st[i].se] = true;
    }
    vector<int> good;
    for (int i = 1; i <= 2 * n; ++i)
        if (!used[i]) good.pb(i);

    for (int i = 0; i < size(good) / 2; ++i)
        st.pb(good[i], good[i + size(good) / 2]);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (inter(st[i], st[j])) ++res;
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