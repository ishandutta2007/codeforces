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

const int V = 200100;

int a[V], b[V];

bool ok(int u) {
    //return a[u] == 0 && b[u] > 0;
    return a[u] == 0;
}
int n, m, Q, u, v, w;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            if (u > v) swap(u, v);
            a[u]++;
            ++b[v];
            ++b[u];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) if(ok(i)) ++ans;
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d", &w);
            if (w == 1) {
                scanf("%d%d", &u, &v);
                if (u > v) swap(u, v);
                if(ok(u)) --ans;
                if(ok(v)) --ans;
                ++a[u];
                ++b[u];
                ++b[v];
                if(ok(u)) ++ans;
                if(ok(v)) ++ans;
            } else if (w == 2) {
                scanf("%d%d", &u, &v);
                if (u > v) swap(u, v);
                if(ok(u)) --ans;
                if(ok(v)) --ans;
                --a[u];
                --b[u];
                --b[v];
                if(ok(u)) ++ans;
                if(ok(v)) ++ans;
            } else {
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

/*
4 3
2 1
1 3
3 4
4
3
1 2 3
2 3 1
3

4 3
2 3
3 4
4 1
1
3
*/