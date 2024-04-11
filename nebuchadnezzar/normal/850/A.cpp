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

struct point {
    ll a, b, c, d, e;
    point(ll _a, ll _b, ll _c, ll _d, ll _e) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        e = _e;
    }
    ll operator*(point p) {
        return a * p.a + b * p.b + c * p.c + d * p.d + e * p.e;
    }
    point operator-(point p) {
        return point(a - p.a, b - p.b, c - p.c, d - p.d, e - p.e);
    }
    ll dist() {
        return a * a + b * b + c * c + d * d + e * e;
    }
};

int n;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d", &n);

    vector<point> inp;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        inp.puba(point(a, b, c, d, e));
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <= j; ++k) {
                if (i != j && j != k && i != k) {
                    ll tmp = (inp[j] - inp[i]) * (inp[k] - inp[i]);
                    if (tmp > 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            ans.puba(i);
        }
    }

    cout << szof(ans) << "\n";
    for (int num : ans) {
        cout << num + 1 << "\n";
    }
    
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}