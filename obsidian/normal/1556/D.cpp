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
int a[V];
int b[V];

int OR(int i, int j) {
    printf("or %d %d\n", i, j);
    fflush(stdout);
    //int x = b[i] | b[j];
    int x;
    scanf("%d", &x);
    return x;
}

int AND(int i, int j) {
    printf("and %d %d\n", i, j);
    fflush(stdout);
    //int x = b[i] & b[j];
    int x;
    scanf("%d", &x);
    return x;
}
bool cmp(int x, int y) {
    return a[x] < a[y];
}
int n, K, id[V];
int main() {
    while (~scanf("%d%d", &n, &K)) {
        //for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        int o_12 = OR(1, 2);
        int o_13 = OR(1, 3);
        int o_23 = OR(2, 3);
        int a_12 = AND(1, 2);
        int a_13 = AND(1, 3);
        int a_23 = AND(2, 3);
        memset(a, 0, sizeof(a));
        for (int i = 30; i >= 0; --i) {
            int _a, _b, _c;
            if ((o_12 &(1 << i)) == 0) _a = 0;
            else if((a_12 &(1 << i))) _a = 2;
            else _a = 1;
            if ((o_13 &(1 << i)) == 0) _b = 0;
            else if((a_13 &(1 << i))) _b = 2;
            else _b = 1;
            if ((o_23 &(1 << i)) == 0) _c = 0;
            else if((a_23 &(1 << i))) _c = 2;
            else _c = 1;
            int v1 = (_a + _b - _c) / 2;
            int v2 = (_a - _b + _c) / 2;
            int v3 = (-_a + _b + _c) / 2;
            if (v1) a[1] |= (1 << i);
            if (v2) a[2] |= (1 << i);
            if (v3) a[3] |= (1 << i);
        }
        for (int j = 4; j <= n; ++j) {
            int O = OR(1, j);
            int A = AND(1, j);
            for (int i = 30; i >= 0; --i) {
                int c;
                if ((O &(1 << i)) == 0) c = 0;
                else if((A &(1 << i))) c = 2;
                else c = 1;
                if (a[1] & (1 << i)) --c;
                if (c) a[j] |= (1 << i);
            }
        }
        for (int i = 1; i <= n; ++i) id[i] = i;
        sort(id + 1, id + 1 + n, cmp);
        //for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
        printf("finish %d\n", a[id[K]]);
        fflush(stdout);
    }
    return 0;
}

/*
5 4
5 3 3 10 1
7 6
1 6 4 2 3 5 4
*/