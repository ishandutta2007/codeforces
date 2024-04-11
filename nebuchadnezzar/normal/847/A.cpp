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




int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    vector<pii> inp;
    vector<int> starts;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        if (l == -1) {
            starts.puba(i);
        }
        inp.puba({l, r});
    }
    
    int prev = -1;
    vector<bool> used(n);
    for (int i = 0; i < szof(starts); ++i) {
        if (used[starts[i]]) {
            continue;
        }
        int cur = starts[i];
        inp[cur].ff = prev;
        if (prev != -1) {
            inp[prev].ss = cur;
        }
        used[cur] = true;
        prev = cur;
        cur = inp[cur].ss;
        while (cur != -1) {
            used[cur] = true;
            inp[prev].ss = cur;
            inp[cur].ff = prev;
            prev = cur;
            cur = inp[cur].ss;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << inp[i].ff + 1 << " " << inp[i].ss + 1 << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}