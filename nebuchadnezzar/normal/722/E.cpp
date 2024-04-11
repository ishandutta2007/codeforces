#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 5, bd = 21, MAXK = 2005;

ll mpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll tmp = mpow(a, b / 2);
    tmp = tmp * tmp % MOD;
    if (b & 1) {
        tmp = tmp * a % MOD;
    }
    return tmp;
}

ll inv(ll a) {
    return mpow(a, MOD - 2);
}

int n, m, k, s;
ll fact[MAXN], rfact[MAXN];

ll paths(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        return 0;
    }
    return fact[x2 - x1 + y2 - y1] * rfact[x2 - x1] % MOD * rfact[y2 - y1] % MOD;
}

bool cmp(pii p1, pii p2) {
    return p1.ff + p1.ss < p2.ff + p2.ss;
}

ll d[bd][MAXK];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &k, &s);

    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    rfact[MAXN - 1] = inv(fact[MAXN - 1]);

    for (int i = MAXN - 1; i > 0; --i) {
        rfact[i - 1] = rfact[i] * i % MOD;
    }

    vector<pii> inp;
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        inp.puba({x, y});
    }

    sort(bend(inp), cmp);

    //cerr << "@" << endl;
    bool flag = false;
    if (szof(inp) && inp.front() == make_pair(1, 1)) {
        flag = true;
    } else {
        inp.puba({1, 1});
        rotate(inp.begin(), inp.end() - 1, inp.end());
        ++k;
    }

    for (int l = 0; l < bd; ++l) {
        for (int i = k - 1; i >= 0; --i) {
            d[l][i] = paths(inp[i].ff, inp[i].ss, n, m);
            for (int j = i + 1; j < k; ++j) {
                d[l][i] = (d[l][i] - paths(inp[i].ff, inp[i].ss, inp[j].ff, inp[j].ss) * d[l][j]) % MOD;
            }
            for (int j = 0; j < l; ++j) {
                d[l][i] = (d[l][i] - d[j][i]) % MOD;
            }
        }
    }

    
    ll p = 0;
    ll tot = paths(1, 1, n, m);
    for (int i = 0; i < bd; ++i) {
        //cerr << d[i][0] << endl;
        tot = (tot - d[i][0]) % MOD;
        int num = i + flag;
        int val = s;
        for (int j = 0; j < num; ++j) {
            val = (val + 1) / 2;
        }
        p = (p + val * d[i][0]) % MOD;
    }

    p = (p + tot) % MOD;

    if (p < 0) {
        p += MOD;
    }

    p = p * inv(paths(1, 1, n, m)) % MOD;

    cout << p << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}