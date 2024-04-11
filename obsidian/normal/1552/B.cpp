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
const int V = 50010;

int a[V][6], _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 5; ++j)
                scanf("%d", &a[i][j]);
        }
        int id = 1;
        for (int i = 2; i <= n; ++i) {
            int w = 0;
            for (int j = 0; j < 5; ++j) {
                if (a[id][j] < a[i][j]) ++w;
            }
            if (w < 3) id = i;
        }
        for (int i = 1; i <= n && id != -1; ++i) {
            if (i == id) continue;
            int w = 0;
            for (int j = 0; j < 5; ++j) {
                if (a[id][j] < a[i][j]) ++w;
            }
            if (w < 3) id = -1;
        }
        printf("%d\n", id);
    }
    return 0;
}

/*
4
1
50000 1 50000 50000 50000
3
10 10 20 30 30
20 20 30 10 10
30 30 10 20 20
3
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
6
9 5 3 7 1
7 4 1 6 8
5 6 7 3 2
6 7 8 8 6
4 2 2 4 5
8 3 6 9 4
*/