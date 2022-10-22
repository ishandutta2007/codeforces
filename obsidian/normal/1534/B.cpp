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
int n, _, a[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        LL ans = 0;
        for (int i = 1; i <= n + 1; ++i) ans += abs(a[i] - a[i - 1]);
        for (int i = 1; i <= n; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans -= a[i] - max(a[i - 1], a[i + 1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
2
4
4 8 9 6
6
2 1 7 4 0 0
*/