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
const int SZ = 2e6 + 5;

int sieve[SZ];
int x, y;

ll calc(int a, int b) {
    return min((ll) y * (b - a), (ll) x);
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d%d%d", &n, &x, &y);

    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
    }

    sort(bend(inp));

    ll ans = INFL;
    
    vector<ll> pref = {0};

    for (auto num : inp) {
        pref.puba(pref.back() + num);
    }

    int amount = x / y;

    for (int i = 2; i < SZ; ++i) {
        if (sieve[i]) {
            continue;
        }
        int c = 0;
        ll cur = 0;
        for (int j = i; j < SZ; j += i) {
            /*while (c < szof(inp) && inp[c] <= j) {
                cur += calc(inp[c], j);
                ++c;
            }*/
            int pos = lower_bound(bend(inp), j - amount) - inp.begin();
            pos = max(pos, c);
            int pos2 = upper_bound(bend(inp), j) - inp.begin();
            //if (i == 2 && j < 120) {
            //    cerr << j << " " << c << " " << pos << " " << pos2 << endl;
            //}
            cur += (ll) y * ((ll) j * (pos2 - pos) - (pref[pos2] - pref[pos])) + (ll) (pos - c) * x;
            c = pos2;
            sieve[j] = 1;
        }                       
        //if (cur == 0) {
        //    cerr << i << endl;
        //}
        ans = min(ans, cur);
    }

    cout << ans << "\n";
    
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}