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
const int V = 10010;
int x[V * 3], y[V * 3], z[V * 3], K, a[V];
void add(int u, int v, int w) {
    x[K] = u;
    y[K] = v;
    z[K] = w;
    K++;
    a[u] -= u * w;
    a[v] += u * w;
}
int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        K = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int s = 0;
        for (int i = 1; i <= n; ++i) s += a[i];
        if (s % n != 0) {
            puts("-1");
            continue;
        }
        for (int i = 2; i <= n; ++i) {
            int need = a[i] % i;
            if (need != 0) {
                add(1, i, i - need);
            }
            add(i, 1, a[i] / i);
        }
        for (int i = 2; i <= n; ++i) add(1, i, s / n);
        //for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
        printf("%d\n", K);
        for (int i = 0; i < K; ++i) printf("%d %d %d\n", x[i], y[i], z[i]);
    }
    return 0;
}

/*
3
4
2 16 4 18
6
1 2 3 4 5 6
5
11 19 1 1 3
*/