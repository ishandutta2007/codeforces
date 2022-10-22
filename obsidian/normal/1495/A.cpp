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
int _, n, a[V], b[V], x, y;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int xn = 0, yn = 0;
        for (int i = 0; i < 2 * n; ++i) {
            scanf("%d%d", &x, &y);
            if (y == 0) a[xn++] = abs(x);
            else b[yn++] = abs(y);
        }
        sort(a, a + n);
        sort(b, b + n);
        double ans = 0.0;
        for (int i = 0; i < n; ++i) {
            //ans += pow(1.0 * a[i] * a[i] + 1.0 * b[n - i - 1] * b[n - i - 1], 0.5);
            ans += pow(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i], 0.5);
        }
        printf("%.12f\n", ans);
    }
    return 0;
}

/*
3
2
0 1
1 0
0 -1
-2 0
4
1 0
3 0
-5 0
6 0
0 3
0 1
0 2
0 4
5
3 0
0 4
0 -3
4 0
2 0
1 0
-3 0
0 -10
0 -2
0 -10
*/