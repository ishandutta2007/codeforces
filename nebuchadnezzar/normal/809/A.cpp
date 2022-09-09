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
const int MOD = 1e9 + 7;


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

    sort(bend(inp));

    vector<ll> bpow = {1};

    for (int i = 0; i < n; ++i) {
        bpow.puba(bpow.back() * 2 % MOD);
    }

    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        //cerr << cur << " " << inp[i] * (bpow[i] - 1) << endl;
        if (i) {
            ans = (ans + inp[i] * (bpow[i] - 1) - cur) % MOD;
        }
        cur = (cur * 2 + inp[i]) % MOD;
    }

    if (ans < 0) {
        ans += MOD;
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}