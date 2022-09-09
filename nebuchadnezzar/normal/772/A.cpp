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
const ll INFL = 1e18 + 100500;
const double PI = atan2(0, -1);

int n, p;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &p);

    vector<pii> inp;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &b, &a);
        inp.puba({a, b});
    }

    double l = 0, r = INFL;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        double sum = 0;
        for (pii g : inp) {
            sum += max(0.0, -(g.ff - g.ss * mid));
        }
        if (p * mid >= sum) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (l > INFL / 2) {
        cout << "-1\n";
        return 0;
    }

    printf("%.10f\n", l);

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}