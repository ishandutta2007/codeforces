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
int a[V][V], vis[V][V], b[V][V], _, n, m;

struct Node{
    int x, y, z;
}e[V * V];
bool cmp(Node x, Node y) {
    return x.z < y.z;
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        int en = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               scanf("%d", &a[i][j]);
               e[en++] = {i, j, a[i][j]};
               vis[i][j] = 0;
               b[i][j] = -1;
            }
        }
        sort(e, e + en, cmp);
        for (int i = 0; i < m; ++i) {
            vis[e[i].x][e[i].y] = 1;
            b[e[i].x][i] = e[i].z;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j]) continue;
                int id = -1;
                for (int k = 0; k < m; ++k) {
                    if (b[i][k] == -1) {id = k; break;}
                }
                b[i][id] = a[i][j];
            }
        }
        for (int i = 0; i < n; ++i, puts("")) {
            for (int j = 0; j < m; ++j)
                printf("%d ", b[i][j]);
        }
    }
    return 0;
}

/*
2
2 3
2 3 4
1 3 5
3 2
2 3
4 1
3 5
*/