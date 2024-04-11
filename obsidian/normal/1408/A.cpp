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
int a[3][V], _, n;;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[cur][i]);
            if (i == n - 1) break;
            if (i == n - 2) {
                for (int j = 0; j < 3; ++j) if (a[j][i + 1] != a[cur][i] && a[j][i + 1] != a[0][0]) {cur = j; break;}
            }
            else {
                if (a[cur][i] == a[cur][i + 1]) cur = (cur + 1) % 3;
            }
        }
        puts("");
    }
    return 0;
}

/*
5
3
1 1 1
2 2 2
3 3 3
4
1 2 1 2
2 1 2 1
3 4 3 4
7
1 3 3 1 1 1 1
2 4 4 3 2 2 4
4 2 2 2 4 4 2
3
1 2 1
2 3 3
3 1 2
10
1 1 1 2 2 2 3 3 3 1
2 2 2 3 3 3 1 1 1 2
3 3 3 1 1 1 2 2 2 3
*/