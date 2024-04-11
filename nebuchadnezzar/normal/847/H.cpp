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

    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);

        inp.puba(num);
    }
    
    vector<ll> lr = {0};
    vector<int> minv = {inp[0]};
    for (int i = 1; i < n; ++i) {
        minv.puba(max(minv.back() + 1, inp[i]));
        lr.puba(lr.back() + minv.back() - inp[i]);
    }

    ll ans = INFL;
    ll sum = 0;
    int minh = inp[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        int ch = max(minh, minv[i]);
        ans = min(ans, ch - inp[i] + sum + lr[i] - (minv[i] - inp[i]));
        if (i) {
            sum += minh - inp[i];
            minh = max(minh + 1, inp[i - 1]);
        }
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}