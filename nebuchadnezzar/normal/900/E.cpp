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

const int MAXL = 1e5 + 5, MAXN = 1e5 + 5;
char buf[MAXL];
pii d[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d", &n);
    scanf("%s", buf);
    scanf("%d", &m);
    
    vector<int> poses[2][2];
    vector<int> ques;
    for (int i = 0; i < n; ++i) {
        if (buf[i] != '?') {
            poses[i % 2][buf[i] - 'a'].puba(i);
        }
        ques.puba(buf[i] == '?');
    }
    vector<int> pref = {0};

    for (int num : ques) {
        pref.puba(num + pref.back());
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            poses[i][j].puba(MAXL);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (i + m <= n) {
            if (i + m <= *lower_bound(bend(poses[i % 2][1]), i) && i + m <= *lower_bound(bend(poses[1 - i % 2][0]), i)) {
                //cerr << i << " -> " << i + m << endl;
                d[i + m] = max(d[i + m], {d[i].ff + 1, d[i].ss - (pref[i + m] - pref[i])});
            }
        }
        d[i + 1] = max(d[i + 1], d[i]);
    }

    cout << -d[n].ss << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}