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
int s[V], _, n, x;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            s[abs(x)]++;
        }
        int ans = 0;
        for (int i = 1; i <= 100; ++i) ans += min(2, s[i]);
        ans += min(1, s[0]);
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
4
1 1 2 2
3
1 2 3
2
0 0
*/