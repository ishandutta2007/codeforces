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

const int MAXN = 105;
int amount[MAXN], last[MAXN];


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, k, m, a;
    scanf("%d%d%d%d", &n, &k, &m, &a);

    memset(last, -1, sizeof last);

    for (int i = 0; i < a; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        amount[num]++;
        last[num] = i;
    }

    for (int i = 0; i < n; ++i) {
        int tmp = amount[i] + m - a;
        int tmp2 = last[i];
        if (m - a) {
            tmp2 = m - 1;
        }
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (amount[j] > tmp || (amount[j] == tmp && last[j] < tmp2)) {
                    ++cnt;
                }
            }
        }
        bool good = true;
        if (cnt >= k || (amount[i] == 0 && m == a)) {
            good = false;
        }
        vector<int> all;
        cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (amount[j] > amount[i] || (amount[j] == amount[i] && last[j] < last[i])) {
                    ++cnt;
                } else {
                    all.puba(amount[j]);
                }
            }
        }
        bool bad = false;
        if (!amount[i]) {
            bad = true;
        }
        if (k < n) {
            sort(bend(all));
            int tot = 0;
            auto it = all.end();
            --it;
            while (cnt < k) {
                tot += amount[i] - *it + 1;
                ++cnt;
                --it;
            }
            if (tot <= m - a) {
                bad = true;
            }
        }
        if (good && bad) {
            cout << "2 ";
        } else if (good) {
            cout << "1 ";
        } else {
            cout << "3 ";
        }
    }
    
    cout << "\n";
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}