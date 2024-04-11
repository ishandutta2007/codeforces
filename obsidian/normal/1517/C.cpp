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
const int V = 510;
int a[V][V], n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i][i]);
        for (int i = n - 1; i > 0; --i) {
            bool one = false;
            for (int j = 1; j <= i; ++j) {
                int y = j;
                int x = j + n - i;
                if (a[x - 1][y] == 1) one = true;
                if (one) a[x][y] = a[x][y + 1] - 1;
                else a[x][y] = a[x - 1][y] - 1;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            for (int j = 1; j <= i; ++j) {
                int y = j;
                int x = j + n - i;
                a[x][y] += n - i;
            }
        }
        for (int i = 1; i <= n; ++i, puts("")) {
            for (int j = 1; j <= i; ++j) {
                printf("%d ", a[i][j]);
            }
        }
    }
    return 0;
}

/*
3
2 3 1

5
1 2 3 4 5
*/