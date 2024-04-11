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
int a[V], b[V], _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        int ra = n / 4, rb = n / 4 - 1;
        LL sa = 0, sb = 0;
        for (int i = ra; i < n; ++i) sa += a[i];
        for (int i = rb + 1; i < n; ++i) sb += b[i];
        //printf("S %d %d %d %lld %lld\n", 0, ra, rb, sa, sb);
        int ans = 0;
        for (int i = n; ; ++i) {
            if (sa >= sb) break;
            int rn = (i + 1) / 4;
            a[i] = 100;
            b[i] = 0;
            sa += 100;
            if (rn > ra) {
                sa -= a[ra];
                ++ra;
            }
            else {
                if (rb >= 0) {
                    sb += b[rb];
                    --rb;
                }
            }
            //printf("S %d %d %d %lld %lld\n", i, ra, rb, sa, sb);
            ans = i - n + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
1
100
0
1
0
100
4
20 30 40 50
100 100 100 100
4
10 20 30 40
100 100 100 100
7
7 59 62 52 27 31 55
33 35 50 98 83 80 64
*/