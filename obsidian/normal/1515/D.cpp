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

int _, n, L, R, a[V], c[2][V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &L, &R);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) c[0][i] = c[1][i] = 0;
        for (int i = 0; i < L; ++i) c[0][a[i]]++;
        for (int i = L; i < n; ++i) c[1][a[i]]++;
        for (int i = 1; i <= n; ++i) {
            int mi = min(c[0][i], c[1][i]);
            c[0][i] -= mi;
            c[1][i] -= mi;
        }
        int id = -1, mx = 0, tot = 0;
        for (int i = 0; i < 2; ++i) {
            int s = 0;
            for (int j = 1; j <= n; ++j) s += c[i][j];
            if (id == -1 || mx < s) id = i, mx = s;
            tot += s;
        }
        int N = (mx - (tot - mx)) / 2;
        int P = 0;
        for (int i = 1; i <= n; ++i) P += c[id][i] / 2;
        //printf("%d %d %d %d %d\n", id, tot, mx, N, P);
        printf("%d\n", N + max(0, tot / 2 - min(N, P)));
    }
    return 0;
}

/*
4
6 3 3
1 2 3 2 2 2
6 2 4
1 1 2 2 2 2
6 5 1
6 5 4 3 2 1
4 0 4
4 4 4 3
*/