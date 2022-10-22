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
int gcd(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    return gcd(y, x % y);
}
int _, n, a[1200], vis[1200];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int gd = 0;
        for (int i = 0; i < n; ++i) vis[i] = 0;
        for (int i = 0; i < n; ++i) {
            int id = -1, mx = -1;
            for (int j = 0; j < n; ++j) {
                if (vis[j]) continue;
                int tg = gcd(gd, a[j]);
                if (id == -1 || mx < tg) id = j, mx = tg;
            }
            vis[id] = 1;
            gd = mx;
            printf("%d ", a[id]);
        }
        puts("");
    }
    return 0;
}

/*
7
2
2 5
4
1 8 2 3
3
3 8 9
5
64 25 75 100 50
1
42
6
96 128 88 80 52 7
5
2 4 8 16 17
*/