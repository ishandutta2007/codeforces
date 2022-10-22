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

int _, n, a[1200], m;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; ++i) if (a[i] == 0) ++c0; else ++c1;
        if (c0 >= n / 2) {
            printf("%d\n", n / 2);
            for (int i = 0; i < n / 2; ++i) printf("%d ", 0); puts("");
        }
        else {
            m = n / 2;
            if (m % 2 == 1) ++m;
            printf("%d\n", m);
            for (int i = 0; i < m; ++i) printf("%d ", 1); puts("");
        }
    }
    return 0;
}

/*
4
2
1 0
2
0 0
4
0 1 1 1
4
1 1 0 0
*/