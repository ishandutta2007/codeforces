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

int calc(int num) {
    int ret = 0;
    while (num) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    vector<int> ans;
    for (int i = 0; i < 100; ++i) {
        if (n - i > 0 && calc(n - i) == i) {
            ans.puba(n - i);
        }
    }
    
    sort(bend(ans));

    cout << szof(ans) << "\n";

    for (int num : ans) {
        cout << num << "\n";
    }
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}