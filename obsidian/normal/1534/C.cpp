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
const int V = 400100;
int _, n, a[V], b[V], pa[V], pb[V], f[V];

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

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        for (int i = 0; i < n; ++i) pa[a[i]] = i;
        for (int i = 0; i < n; ++i) pb[b[i]] = i;
        for (int i = 0; i <= n; ++i) f[i] = i;
        for (int i = 1; i <= n; ++i) {
            U(pa[i], pb[i]);
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) if (f[i] == i) ans = (ans * 2) % P;
        printf("%d\n", ans);
    }
    return 0;
}

/*
2
4
1 4 2 3
3 2 1 4
8
2 6 5 1 4 3 7 8
3 8 7 5 1 2 4 6
*/