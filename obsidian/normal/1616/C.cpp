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
const int V = 75;
int a[V], _, n;
int main(){
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int ans = n - 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int df = 0;
                for (int k = 1; k <= n; ++k) {
                    if ((k - i) * (a[j] - a[i]) != (a[k] - a[i]) * (j - i)) ++df;
                }
                ans = min(ans, df);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
4
1 2 3 4
4
1 1 2 2
2
0 -1
6
3 -2 4 -1 -4 0
1
-100
*/