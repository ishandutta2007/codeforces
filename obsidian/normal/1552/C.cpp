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
const int V = 210;
int _, n, m, a[V], b[V], c[V], s[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) scanf("%d%d", &a[i], &b[i]);
        for (int i = 0; i < m; ++i) if (a[i] > b[i]) swap(a[i], b[i]);
        for (int i = 1; i <= 2 * n; ++i) c[i] = 1;
        for (int i = 0; i < m; ++i) c[a[i]] = c[b[i]] = 0;
        s[0] = 0;
        for (int i = 1; i <= 2 * n; ++i) s[i] = s[i - 1] + c[i];
        int re = n - m;
        int ans = re * (re - 1) / 2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                int x = max(a[i], a[j]);
                int y = min(b[i], b[j]);
                bool cover = false;
                if (a[i] < a[j] && b[i] > b[j]) cover = true;
                if (a[j] < a[i] && b[j] > b[i]) cover = true;
                if (x < y && !cover) ++ans;
            }
        }
        for (int i = 0; i < m; ++i) {
            int x = s[b[i]] - s[a[i]];
            int y = 2 * re - x;
            ans += min(x, y);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
4 2
8 2
1 5
1 1
2 1
2 0
10 6
14 6
2 20
9 10
13 18
15 12
11 7
*/