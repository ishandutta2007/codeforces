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
const int V = 110;
int a[V], ans[V], n, K, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int s = 0;
        for (int i = 0; i < n; ++i) s += a[i];
        if (K == s) {
            puts("NO");
            continue;
        }
        s = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s + a[i] == K) {
                ans[n - 1] = a[i];
            } else {
                ans[cur++] = a[i];
                s += a[i];
            }
        }
        puts("YES");
        for (int i = 0; i < n; ++i) printf("%d ", ans[i]); puts("");
    }
    return 0;
}

/*
3
3 2
3 2 1
5 3
1 2 3 4 8
1 5
5
*/