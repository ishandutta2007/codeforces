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
const int V = 60;
int a[V], vis[120], _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) vis[a[i] - a[j]] = 1;
        }
        int ans = 0;
        for (int i = 0; i <= 100; ++i) ans += vis[i];
        printf("%d\n", ans);
    }
    return 0;
}

/*
8
4
1 2 4 5
3
1 3 5
3
2 6 8
2
1 2
1
50
5
3 4 5 6 8
3
1 25 26
6
1 2 4 8 16 32
*/