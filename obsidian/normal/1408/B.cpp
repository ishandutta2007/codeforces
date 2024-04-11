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
int a[V], _, n, K;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int diff = 1;
        for (int i = 1; i < n; ++i) if(a[i] != a[i - 1]) ++diff;
        if (K == 1) {
            if (diff > 1) puts("-1");
            else puts("1");
            continue;
        }
        printf("%d\n", max(1, (diff - 1 + K - 2) / (K - 1)));
    }
    return 0;
}

/*
6
4 1
0 0 0 1
3 1
3 3 3
11 3
0 1 2 2 3 3 3 4 4 4 4
5 3
1 2 3 4 5
9 4
2 2 3 5 7 11 13 13 17
10 7
0 1 1 2 3 3 4 5 5 6
*/