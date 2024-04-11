#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int n, m;
map<int, int> cur;
vector<int> color;
ll factorial[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    color.resize(m);
    cur[0] = m;

    int c = 1;

    for (int i = 0; i < n; ++i) {
        int q;
        scanf("%d", &q);
        map<int, int> now;
        for (int j = 0; j < q; ++j) {
            int t;
            scanf("%d", &t);
            --t;
            now[t]++;
        }
        map<pii, int> changed;
        map<pii, int> newc;
        for (auto p : now) {
            changed[{color[p.ff], p.ss}]++;
            newc[{color[p.ff], p.ss}] = c++;
        }
        for (auto p : now) {
            cur[color[p.ff]]--;
            color[p.ff] = newc[{color[p.ff], p.ss}];
            cur[color[p.ff]]++;
        }
    }

    ll ans = 1;
    factorial[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    for (auto p : cur) {
        ans = (ans * factorial[p.ss]) % MOD;
    }
    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}