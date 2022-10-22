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
int a[V], vis[V], b[V], rd;
//int p[V], q[V];
int Q(int u) {
    ++rd;
    printf("? %d\n", u);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    return v;
}

void solve(int n) {
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    //Q(1);
    rd = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 1) continue;
        int m = 0;
        int u = Q(i);
        while (1) {
            int v = Q(i);
            b[m++] = v;
            if (v == u)
            break;
        }
        for (int j = 0; j < m; ++j) vis[b[j]] = 1;
        //for (int j = 0; j < m; ++j) printf("%d ", b[j]); printf("R %d\n", rd);
        for (int j = 0; j < m; ++j) {
            //a[b[j]] = b[(j + rd) % m];
            int cur = (j - rd % m + 2 * m) % m;
            //printf("B %d\n", cur);
            a[b[cur]] = b[(cur + 1) % m];
        }
    }
    printf("!"); for (int i = 1; i <= n; ++i) printf(" %d", a[i]); puts("");
    fflush(stdout);
}

int main() {
    int _, n;
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}

/*

*/