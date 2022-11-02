#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1e3 + 10;

int a[N][N];

int main() {
    int n;
    scanf("%d", &n);
    int minx = +2e9, maxx = -2e9, miny = +2e9, maxy = -2e9;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    int side = max(maxx - minx, maxy - miny);
    printf("%I64d\n", 1LL * side * side);
    return 0;
}