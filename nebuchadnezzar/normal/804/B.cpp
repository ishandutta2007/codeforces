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
const int MAXN = 1e6 + 5;             
const ll MOD = 1e9 + 7;

char buf[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%s", buf);
    
    string s = buf;
    
    ll ans = 0;

    reverse(bend(s));

    ll p = 1;
    ll cnt = 0;
    while (szof(s)) {
        while (szof(s) && s.back() == 'b') {
            ans = (ans + p - 1 + MOD) % MOD;
            s.pop_back();
        }
        while (szof(s) && s.back() == 'a') {
            s.pop_back();
            cnt++;
            p = (p * 2) % MOD;
        }
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}