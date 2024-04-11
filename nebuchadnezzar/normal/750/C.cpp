#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 7;
const double PI = atan2(0, -1);

int n;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    ll l = -INFL, r = INFL;

    for (int i = 0; i < n; ++i) {
        int c, d;
        scanf("%d%d", &c, &d);
        if (d == 1) {
            l = max(l, 1900ll);
        } else {
            r = min(r, 1899ll);
        }
        l += c;
        r += c;
    }


    if (l > r) {
        cout << "Impossible\n";
    } else if (r > INFL / 2) {
        cout << "Infinity\n";
    } else {
        cout << r << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}