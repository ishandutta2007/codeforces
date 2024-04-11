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

/*
int ans = 0;

int rec(int rest, int gcd) {
    if (!rest) {
        if (gcd == 1) {
            ++ans;
        }
        return 0;
    }
    for (int i = 1; i <= rest; ++i) {
        rec(rest - i, __gcd(gcd, i));
    }
    return 0;
}*/

const int MOD = 1e9 + 7;

int mpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ll) ret * a % MOD;
        }
        b /= 2;
        a = (ll) a * a % MOD;
    }
    return ret;
}

map<int, int> mem;

int calc(int num) {
    if (mem.count(num)) {
        return mem[num];
    }
    if (num <= 2) {
        return 1;
    }
    int& val = mem[num];
    val = mpow(2, num - 1);
    for (int i = 1; i * i <= num; ++i) {
        //cerr << num << " " << i << endl;
        if (num % i == 0) {
            val = (val - calc(i)) % MOD;
            if (i > 1 && i * i < num) {
                val = (val - calc(num / i)) % MOD;
            }
        }
    }
    if (val < 0) {
        val += MOD;
    }
    return val;
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int x, y;
    scanf("%d%d", &x, &y);

    if (y % x != 0) {
        cout << "0\n";
        return 0;
    }

    y /= x;
    
    cout << calc(y) << "\n";

    //cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}