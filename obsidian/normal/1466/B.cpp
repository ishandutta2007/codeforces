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
const int V = 100100;
int a[V];
int vis[3 * V];
int _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i <= 3 * n; ++i) vis[i] = 0;
        for (int i = 2; i <= n; ++i) if (a[i] <= a[i - 1]) ++a[i];
        for (int i = 1; i <= n; ++i) vis[a[i]] = 1;
        int ans = 0;
        for (int i = 0; i <= 3 * n; ++i) ans += vis[i];
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
6
1 2 2 2 5 6
2
4 4
6
1 1 3 4 4 5
1
1
6
1 1 1 2 2 2
*/