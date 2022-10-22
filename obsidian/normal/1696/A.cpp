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
const int V = 2100;

int _, n, a[V], Z;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &Z);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, a[i] | Z);
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
2 3
3 4
5 5
0 2 4 6 8
1 9
10
5 7
7 15 30 29 27
3 39548743
10293834 10284344 13635445
*/