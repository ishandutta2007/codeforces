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

int _, n, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int mx = 0;
        for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
        int L = n, R = -1, c = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) {
                L = min(L, i);
                R = max(R, i);
                ++c;
            }
        }
        if (mx == 0) puts("0");
        else if (R - L + 1 == c) puts("1");
        else puts("2");
    }
    return 0;
}

/*
4
4
0 0 0 0
5
0 1 2 3 4
7
0 2 3 0 1 2 0
1
1000000000
*/