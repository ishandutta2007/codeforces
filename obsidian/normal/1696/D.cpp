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
const int V = 250100;
int mi[V], mx[V], a[V], n, _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        mi[n] = mx[n] = n + 1;
        for (int i = n - 1; i > 0; --i) {
            mi[i] = mx[i] = i + 1;
            a[n + 1] = -1;
            while (a[mi[i]] > a[i]) mi[i] = mi[mi[i]];
            a[n + 1] = n + 1;
            while (a[mx[i]] < a[i]) mx[i] = mx[mx[i]];
        }
        //for (int i = 1; i <= n; ++i) printf("%d %d %d\n", i, mi[i], mx[i]);
        int ans = 0;
        int u = 1;
        while (u != n) {
            //printf("U %d\n", u);
            int v = u;
            if (a[u] > a[u + 1]) {
                while (mi[v] != n + 1 && mi[v] < mx[u]) v =mi[v];
            } else {
                while (mx[v] != n + 1 && mx[v] < mi[u]) v =mx[v];
            }
            u = v;
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
1
1
2
1 2
5
1 4 2 3 5
5
2 1 5 3 4
10
7 4 8 1 6 10 3 5 2 9
*/