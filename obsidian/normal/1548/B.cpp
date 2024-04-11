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
const int M = 18;

LL f[V][M + 1], a[V];
int pt[M + 1];
int _, n;


int main() {
    pt[0] = 1;
    for(int i = 1; i <= M; ++i) pt[i] = pt[i - 1] * 2;
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        if (n == 1) {
            puts("1");
            continue;
        }
        --n;
        for (int i = 0; i < n; ++i) f[i][0] = abs(a[i] - a[i + 1]);
        //for (int i = 0; i < n; ++i) if (f[i][0] != 1) printf("F %d %d %lld\n", i, 0, f[i][0]);
        for (int j = 1; j <= M; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i + pt[j] > n) f[i][j] = 1;
                else f[i][j] = __gcd(f[i][j - 1], f[i + pt[j - 1]][j - 1]);
                //if (f[i][j] != 1) printf("F %d %d %lld\n", i, j, f[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cur = i;
            LL pre = 0;
            for (int j = M; j >= 0; --j) {
                if (cur + pt[j] > n) continue;
                LL gd = __gcd(pre, f[cur][j]);
                if (gd != 1) cur += pt[j], pre = gd;
            }
            //printf("C %d %d\n", i, cur);
            ans = max(ans, cur - i);
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}

/*
4
5
1 5 2 4 6
4
8 2 5 10
2
1000 2000
8
465 55 3 54 234 12 45 78
*/