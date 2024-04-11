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
    
    int n, s;
    scanf("%d%d", &n, &s);

    ll sum = 0;
    ll ans = 0;
    vector<pii> change;
    for (int i = 0; i < n; ++i) {
        int si, ai, bi;
        scanf("%d%d%d", &si, &ai, &bi);
        ans += (ll) ai * si;
        change.puba({bi - ai, si});
        //inp.puba({si, ai, bi});
        sum += si;
    }
    
    ll amount = (sum + s - 1) / s;

    sort(bend(change));

    ll sz = 0;
    int c = szof(change) - 1;
    while (c >= 0 && change[c].ff >= 0) {
        sz += change[c].ss;
        --c;
    }
    

    ll best = 0;
    ll flip = sz / s;
    for (int i = -2; i <= 2; ++i) {
        if (0 <= i + flip && i + flip <= amount) {
            ll cur_flip = (i + flip) * s;
            ll cur = 0;
            ll pos = 0;
            ll min_flip = cur_flip - (amount * s - sum);
            for (int j = szof(change) - 1; j >= 0; --j) {
                if (change[j].ff >= 0) {
                    if (pos + change[j].ss <= cur_flip) {
                        pos += change[j].ss;
                        cur += (ll) change[j].ss * change[j].ff;
                    } else {
                        cur += (ll) (cur_flip - pos) * change[j].ff;
                        break;
                    }
                } else {
                    if (pos + change[j].ss <= min_flip) {
                        pos += change[j].ss;
                        cur += (ll) change[j].ss * change[j].ff;
                    } else {
                        if (min_flip >= pos) {
                            cur += (ll) (min_flip - pos) * change[j].ff;
                        }
                        break;
                    }
                }
            }

            best = max(best, cur);
        }
    }

    cout << ans + best << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}