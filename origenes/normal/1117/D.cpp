#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 112;
const int MOD = 1e9 + 7;

ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

ll mul(ll a, ll b) {
    return a * b % MOD;
}

ll n;
int m;

struct Mat {
    ll a[maxn][maxn];

    Mat() {
        reset(a, 0);
    }

    Mat operator * (const Mat &rhs) {
        Mat ret;
        REP(i, m) REP(j, m) REP(k, m) ret.a[i][j] = add(ret.a[i][j], mul(a[i][k], rhs.a[k][j]));
        return ret;
    }
};

Mat pow_mod(ll pw, Mat a) {
    Mat ret;
    REP(i, m) ret.a[i][i] = 1;
    while (pw) {
        if (pw & 1) ret = ret * a;
        a = a * a;
        pw >>= 1;
    }
    return ret;
}

int main() {
    cin >> n >> m;
    if (n < m) {
        cout << 1;
        return 0;
    }
    if (n == m) {
        cout << 2;
        return 0;
    }
    Mat M;
    M.a[0][0] = 1, M.a[0][m - 1] = 1;
    FOR(i, 1, m - 1) M.a[i][i - 1] = 1;
    M = pow_mod(n - m, M);
    vector<ll> v(m, 1);
    v[0] = 2;
    ll ans = 0;
    REP(i, m) ans = add(ans, mul(v[i], M.a[0][i]));
    cout << ans;
}