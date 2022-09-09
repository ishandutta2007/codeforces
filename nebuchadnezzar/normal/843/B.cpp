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
const int SZ = 995;
const int MAXN = 1e5 + 5;
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

int n, s, x;
int ans = INF;
pii mem[MAXN];
int cnt = 0;

vector<int> order;
vector<int> rev;

pii ask(int pos) {
    pos = order[pos];
    if (mem[pos].ff != -1) {
        return mem[pos];
    }
    if (cnt == 1999) {
        if (ans == INF) {
            ans = -1;
        }
        cout << "! " << ans << "\n";
        exit(0);
    }
    cout << "? " << pos + 1 << endl;
    ++cnt;
    int value, next;
    scanf("%d%d", &value, &next);
    if (next > 0) {
        --next;
        next = rev[next];
    }
    if (value >= x) {
        ans = min(ans, value);
    }
    return mem[pos] = {value, next};
}

ll mrand() {
    return (ll) rand() * (RAND_MAX + 1) + rand();
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    memset(mem, -1, sizeof mem);

    scanf("%d%d%d", &n, &s, &x);
    for (int i = 0; i < n; ++i) {
        order.puba(i);
    }
    //random_shuffle(bend(order));
    shuffle(bend(order), tw);
    rev = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        rev[order[i]] = i;
    }
    --s;

    s = rev[s];

    if (n <= 1999) {
        for (int i = 0; i < n; ++i) {
            ask(i);
        }
        if (ans == INF) {
            ans = -1;
        }
        cout << "! " << ans << "\n";
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        int l = mrand() % (n - SZ + 1);
        int best = 0, pos = s;
        for (int j = 0; j < SZ; ++j) {
            //cerr << j << endl;
            pii p = ask(l + j);
            if (p.ff < x) {
                if (best < p.ff) {
                    best = p.ff;
                    pos = l + j;
                }
            }
        }
        //cerr << "start " << pos << endl;
        for (int j = 0; j < SZ; ++j) {
            pii p = ask(pos);
            if (p.ss == -1) {
                break;
            }
            pos = p.ss;
        }
    }

    if (ans == INF) {
        ans = -1;
    }

    cout << "! " << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}