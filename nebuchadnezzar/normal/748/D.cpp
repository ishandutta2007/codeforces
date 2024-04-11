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
const int MAXL = 1e5 + 5;
const int P = 239, MOD = 1e9 + 7;

int n, k;
char buf[MAXL];

map<pii, vector<int>> have;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &k, &n);

    for (int i = 0; i < k; ++i) {
        int cost;
        scanf("%s%d", buf, &cost);
        int h = 0, rh = 0;
        for (int j = 0; j < n; ++j) {
            h = ((ll) h * P + buf[j]) % MOD;
            rh = ((ll) rh * P + buf[n - 1 - j]) % MOD;
        }
        have[{h, rh}].puba(cost);
        //cerr << h << " " << rh << endl;
    }

    for (auto& p : have) {
        sort(bend(p.ss));
    }

    ll ans = 0;
    int best = 0;
    for (auto& p : have) {
        if (p.ff.ff == p.ff.ss) {
            int last = 0;
            while (szof(p.ss) >= 2 && p.ss[szof(p.ss) - 2] + p.ss.back() > 0) {
                ans += p.ss.back();
                p.ss.pop_back();
                ans += p.ss.back();
                last = min(last, p.ss.back());
                p.ss.pop_back();
            }
            if (szof(p.ss)) {
                best = max(best, p.ss.back());
            }
            best = max(best, -last);
        } else {
            pii other = {p.ff.ss, p.ff.ff};
            auto& v = have[other];
            while (szof(p.ss) && szof(v) && p.ss.back() + v.back() > 0) {
                ans += p.ss.back();
                p.ss.pop_back();
                ans += v.back();
                v.pop_back();
            }
        }
    }

    ans += best;

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}