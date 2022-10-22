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
int f[V];
int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return;
    f[px] = py;
}
int cnt[V], a[V], b[V], _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        for (int i = 1; i <= n; ++i) f[i] = i, cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            U(a[i], b[i]);
        }
        for (int i = 1; i <= n; ++i) cnt[fd(i)]++;
        int w = 0;
        for (int i = 1; i <= n; ++i) w += cnt[i] / 2;
        LL ans = 0;
        for (int i = 0; i < w; ++i) ans += (n - 2 * i - 1) * 2;
        printf("%lld\n", ans);
    }
    return 0;
}

/*
3
6
1 5 4 3 2 6
5 3 1 4 6 2
6
3 5 4 6 2 1
3 6 4 5 2 1
1
1
1
*/