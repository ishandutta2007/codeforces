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
int a[V], _, n, K;
LL s[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
        LL ans = 0;
        if (K <= n) {
            for (int i = K; i <= n; ++i) ans = max(ans, s[i] - s[i - K]);
            ans += (LL) (K - 1) * K / 2;
        } else {
            ans = s[n];
            ans += (LL) K * n;
            ans -= (LL) n * (n + 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*
4
5 2
5 6 1 2 3
5 7
5 6 1 2 3
1 2
999999
5 70000
1000000000 1000000000 1000000000 1000000000 1000000000
*/