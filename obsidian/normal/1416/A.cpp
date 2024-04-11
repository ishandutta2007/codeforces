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
const int oo = 1000000000;
const int P = 1000000007;
const int V = 300100;
int a[V], last[V], res[V], ans[V], n, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) last[i] = res[i] = 0;
        for (int i = 1; i <= n; ++i) {
            res[a[i]] = max(res[a[i]], i - last[a[i]]);
            last[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
            res[i] = max(res[i], n + 1 - last[i]);
        for (int i = 0; i <= n; ++i) ans[i] = oo;
        for (int i = 1; i <= n; ++i) {
            if (ans[res[i]] == oo) ans[res[i]] = i;
        }
        for (int i = 1; i <= n; ++i) ans[i] = min(ans[i], ans[i - 1]);
        for (int i = 1; i <= n; ++i) if (ans[i] == oo) ans[i] = -1;
        for (int i = 1; i <= n; ++i) printf("%d ", ans[i]); puts("");
    }
    return 0;
}

/*
3
5
1 2 3 4 5
5
4 4 4 4 2
6
1 3 1 5 3 1
*/