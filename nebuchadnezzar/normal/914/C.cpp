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
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int d[MAXN];
int dcnk[MAXN][MAXN];

int cnk(int n, int k) {
    return dcnk[n][k];
}

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    
    dcnk[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j <= i; ++j) {
            add(dcnk[i][j], dcnk[i - 1][j]);
            if (j) {
                add(dcnk[i][j], dcnk[i - 1][j - 1]);
            }
        }
    }


    string n;
    int k;
    cin >> n >> k;

    if (k == 0) {
        cout << 1 << "\n";
        return 0;
    }

    for (int i = 2; i < MAXN; ++i) {
        d[i] = d[__builtin_popcount(i)] + 1;
    }

    vector<int> v;
    for (int i = 1; i < MAXN; ++i) {
        if (d[i] + 1 == k) {
            v.puba(i);
            //cerr << i << endl;
        }
    }
    
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < szof(n); ++i) {
        if (n[i] == '1') {
            for (int num : v) {
                if (num >= sum && szof(n) - i - 1 >= num - sum) {
                    //cerr << "add " << szof(n) - i - 1 << " " << num - sum << endl;
                    add(ans, cnk(szof(n) - i - 1, num - sum));
                }
            }
        }

        sum += n[i] - '0';
    }

    if (find(bend(v), sum) != v.end()) {
        add(ans, 1);
    }

    if (k == 1) {
        ans = (ans + MOD - 1) % MOD;
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}