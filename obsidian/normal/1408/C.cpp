#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 100100;
int a[V], n, RR, _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &RR);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        double ans = 0.0;
        int pL = 1;
        int pR = n;
        double L = 0.0;
        double R = RR;
        double vL = 1.0;
        double vR = 1.0;
        while (1) {
            if (pL == pR + 1) {
                ans += (R - L) / (vL + vR);
                break;
            }
            if ((a[pL] - L) / vL < (R - a[pR]) / vR) {
                R -= (a[pL] - L) / vL * vR;
                ans += (a[pL] - L) / vL;
                vL += 1.0;
                L = a[pL++];
            } else {
                L += (R - a[pR]) / vR * vL;
                ans += (R - a[pR]) / vR;
                vR += 1.0;
                R = a[pR--];
            }
        }
        printf("%.10f\n", ans);
    }
    return 0;
}

/*
5
2 10
1 9
1 10
1
5 7
1 2 3 4 6
2 1000000000
413470354 982876160
9 478
1 10 25 33 239 445 453 468 477
*/