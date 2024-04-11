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
const double PI = atan2(0, -1);
const long double eps = 1e-14;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);

    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    long double from = 0, to = 1e100;

    for (int i = 0; i < n; ++i) {
        //cerr << i << endl;
        int x, y, dx, dy;
        scanf("%d%d%d%d", &x, &y, &dx, &dy);

        if (dx == 0) {
            if (x <= x1 || x >= x2) {
                cout << "-1\n";
                return 0;
            }
        } else {
            long double cur_from = 0, cur_to = 0;
            if ((x >= x2 && dx > 0) || (x <= x1 && dx < 0)) {
                cout << "-1\n";
                return 0;
            }
            if (x1 < x && x < x2) {
                cur_from = 0;
            } else {
                cur_from = min((long double) (x1 - x) / dx, (long double) (x2 - x) / dx);
            }
            cur_to = max((long double) (x1 - x) / dx, (long double) (x2 - x) / dx);
            from = max(from, cur_from);
            to = min(to, cur_to);
        }

        if (dy == 0) {
            if (y <= y1 || y >= y2) {
                cout << "-1\n";
                return 0;
            }
        } else {
            long double cur_from = 0, cur_to = 0;
            if ((y >= y2 && dy > 0) || (y <= y1 && dy < 0)) {
                cout << "-1\n";
                return 0;
            }
            if (y1 < y && y < y2) {
                cur_from = 0;
            } else {
                cur_from = min((long double) (y1 - y) / dy, (long double) (y2 - y) / dy);
            }
            cur_to = max((long double) (y1 - y) / dy, (long double) (y2 - y) / dy);
            from = max(from, cur_from);
            to = min(to, cur_to);
        }
    }

    //cerr << from << " " << to << endl;

    if (from + eps >= to) {
        cout << "-1\n";
    } else {
        printf("%.15f\n", (double) from);
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}