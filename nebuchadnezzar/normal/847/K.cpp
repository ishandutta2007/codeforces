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

char buf[100];
map<pii, int> vals;
map<string, int> inds;
int get(string s) {
    if (!inds.count(s)) {
        inds[s] = szof(inds);
    }
    return inds[s];
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, a, b, k, f;
    scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);

    int prev = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        int from = get(buf);
        scanf("%s", buf);
        int to = get(buf);
        int cost = a;
        if (from == prev) {
            cost = b;
        }
        vals[{min(from, to), max(from, to)}] += cost;
        prev = to;
    }
    
    ll ans = INFL;
    vector<int> arr;
    ll sum = 0;
    for (auto p : vals) {
        sum += p.ss;
        arr.puba(p.ss);
    }   
    sort(bend(arr));

    for (int i = 0; i <= k; ++i) {
        ans = min(ans, sum + i * f);
        if (szof(arr) > i) {
            sum -= arr[szof(arr) - i - 1];
        } else {
            break;
        }
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}