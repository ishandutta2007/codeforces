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
int _, n, a[120];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n ;++i) scanf("%d", &a[i]);
        sort(a, a + n);
        int s = 0;
        for (int i = 0; i < n; ++i) s += a[i];
        if (s == 0) puts("NO");
        else {
            puts("YES");
            if(s > 0) for (int i = n - 1; i >= 0; --i) printf("%d ", a[i]);
            else for (int i = 0; i < n; ++i) printf("%d ", a[i]);
            puts("");
        }
    }
    return 0;
}

/*
4
4
1 -2 3 -4
3
0 0 0
5
1 -1 1 -1 1
6
40 -31 -9 0 13 -40
*/