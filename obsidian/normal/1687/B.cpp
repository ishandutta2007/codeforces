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
const int V = 510;
int q[V], in[V];
struct Edge{int w, id;}e[V];
bool cmp(Edge x, Edge y) {return x.w < y.w;}
int n, m;
int Q() {
    printf("? ");
    for (int i = 0; i < m; ++i) printf("%d", q[i]); puts("");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < m; ++i) {
            memset(q, 0, sizeof(q));
            q[i] = 1;
            e[i].w = Q();
            e[i].id = i;
        }
        sort(e, e + m, cmp);
        memset(in, 0, sizeof(in));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            memset(q, 0, sizeof(q));
            for (int j = 0; j < i; ++j) q[e[j].id] = in[e[j].id];
            q[e[i].id] = 1;
            int s = Q();
            if (s == ans + e[i].w) {
                in[e[i].id] = 1;
                ans = s;
            }
        }
        printf("! %d\n", ans);
        fflush(stdout);
    }
    return 0;
}

/*

*/