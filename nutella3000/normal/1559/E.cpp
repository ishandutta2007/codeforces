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
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 998244353;

int sum(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}
void add(int&a, int b) { 
    a += b;
    if (a >= mod) a -= mod;
}
int mul(int a, int b) { return a * b % mod; }

int solve(int n, int m, vector<int> l, vector<int> r) {
    for (int i = 0; i < n; ++i)
        m -= l[i], r[i] -= l[i] - 1;
    if (m < 0) return 0;

    vector<int> dp0(m + 1), dp1(m + 1);
    ((n & 1) ? dp1[0] : dp0[0]) = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = m - r[i]; j >= 0; --j) {
            add(dp1[j + r[i]], dp0[j]);
            add(dp0[j + r[i]], dp1[j]);
        }
    }
    vector<int> P(m + 1);
    for (int i = 0; i <= m; ++i)
        P[i] = sum(dp0[i], mod - dp1[i]);
    
    vector<int> G(n + 1);
    G[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = n; j > 0; --j)
            G[j] = sum(G[j - 1], mod - G[j]);
        G[0] = mod - G[0];
    }

    vector<int> Q(m + 1);
    for (int i = 0; i <= m; ++i) {
        Q[i] = mul(P[i], G[0]);
        for (int j = 0; j <= min(n, m - i); ++j)
            add(P[i + j], mod - mul(Q[i], G[j]));
    }
    int res = 0;
    for (int i = 0; i <= m; ++i)
        res += Q[i];
    return res % mod;
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    vector<int> cnt(m + 1);

    for (int i = 1; i <= m; ++i) {
        vector<int> nl(n), nr(n);

        bool bad = false;
        for (int j = 0; j < n; ++j) {
            nl[j] = (l[j] + i - 1) / i, nr[j] = r[j] / i;
            if (nr[j] < nl[j]) bad = true;
        }

        if (bad) continue;
        cnt[i] = solve(n, m / i, nl, nr);
        assert(cnt[i] >= 0 && cnt[i] < mod);
    }

    for (int i = m; i >= 1; --i) {
        for (int j = 2 * i; j <= m; j += i) {
            assert(cnt[i] >= 0 && cnt[i] < mod);
            add(cnt[i], mod - cnt[j]);
        }
    }
    cout << cnt[1] << endl;
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