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
const int V = 1010;

int _, n, a[V];
int s[V][V * 2];int c[V], use[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        s[0][0] = 1;
        c[0] = 1;
        memset(use, 0, sizeof(use));
        for (int i = 1; i < n; ++i) {
            if (a[i] == 1) {
                for (int j = 0; j < c[i - 1]; ++j) s[i][j] = s[i - 1][j];
                c[i] = c[i - 1] + 1;
                s[i][c[i] - 1] = 1;
            } else {
                int id = -1;
                for (int j = c[i - 1] - 1; j >= 0; --j) if (a[i] == s[i - 1][j] + 1) {id = j; break;}
                //printf("Id %d\n", id);
                c[i] = id + 1;
                use[id] = 1;
                for (int j = 0; j < id; ++j) s[i][j] = s[i - 1][j];
                s[i][id] = a[i];
            }
            //printf("C %d\n", c[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < c[i]; ++j) {
                if (j != 0) printf(".");
                printf("%d", s[i][j]);
            }
            puts("");
        }
    }
    return 0;
}

/*
2
4
1
1
2
3
9
1
1
1
2
2
1
2
1
2
*/