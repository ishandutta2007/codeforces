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
const int V = 100100;
int a[V], n;

bool check(int L, int R) {
    LL cnt = 0;
    bool allt = true;
    for (int i = 0; i < n; ++i)
        if (a[i] >= 2 * L) {
            cnt += a[i] / L;
            if (a[i] / L != 2) allt = false;
        }
    if (allt && R % 2 == 1) return false;
    return cnt >= R;
}

int _, L, R;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d",&L, &R, &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        if (check(L, R)) puts("Yes");
        else if (check(R, L)) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
6
4 6 3
12 9 8
3 3 2
8 8
3 3 2
9 5
4 5 2
10 11
5 4 2
9 11
10 10 3
11 45 14
*/