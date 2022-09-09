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
    
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    const int STEPS = 1e7 + 7;

    int cnt = 1;
    for (int i = 0; i < STEPS; ++i) {
        int tmp = a * 10;
        int d = tmp / b;
        if (d == c) {
            cout << cnt << "\n";
            return 0;
        }

        a = tmp % b;

        ++cnt;
    }
    
    cout << "-1\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}