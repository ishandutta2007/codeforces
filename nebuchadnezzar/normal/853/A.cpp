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
    
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> ans(n);
    vector<int> inp;
    set<pii> have;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        while (c < n && c <= i + k) {
            int num;
            scanf("%d", &num);
            have.insert({num, c});
            inp.puba(num);
            ++c;
        }
        int who = (--have.end()) -> ss;
        have.erase(--have.end());
        ans[who] = i + k;
    }
    
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (ll) inp[i] * (ans[i] - i);
    }

    cout << sum << "\n";
    for (int num : ans) {
        cout << num + 1 << " ";
    }
    cout << "\n";
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}