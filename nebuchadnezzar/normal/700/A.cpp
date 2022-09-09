#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, len, v1, v2, k;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d%d%d", &n, &len, &v1, &v2, &k);

    double l = (double) len / v2, r = (double) len / v1;

    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        double l2 = 0, r2 = mid;
        for (int j = 0; j < 100; ++j) {
            double mid2 = (l2 + r2) / 2;
            if (mid2 * v1 + (mid - mid2) * v2 >= len) {
                l2 = mid2;
            } else {
                r2 = mid2;
            }
        }
        double car = mid - l2;
        int parts = (n + k - 1) / k;
        double pos_car = 0, pos_p = 0;
        bool flag = true;
        for (int i = 0; i < parts; ++i) {
            pos_car += v2 * car;
            if (pos_car > len) {
                flag = false;
                break;
            }
            pos_p += v1 * car;
            double rt = (pos_car - pos_p) / (v1 + v2);
            pos_car -= rt * v2;
            pos_p += rt * v1;
        }
        if (flag) {
            r = mid;
        } else {
            l = mid;
        }
    }

    printf("%.10f\n", l);

    return 0;
}