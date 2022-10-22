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
const int V = 25100;
const int Q = 500100;
int u[Q], v[Q], K;
int pt[20], a[20];
void add(int x, int y) {
    u[K] = x;
    v[K] = y;
    K++;
}
int id[V];
void dfs(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    dfs(l, mid);
    dfs(mid + 1, r);
    for (int i = l; i <= mid; ++i) add(id[i], id[i - l + mid + 1]);
}
int n;

int main() {
    pt[0] = 1;
    for (int i = 1; i < 20; ++i) pt[i] = pt[i - 1] * 2;
    while (~scanf("%d", &n)) {
        int m = 0;
        int x = n;
        while (x) {
            a[m++] = x % 2;
            x /= 2;
        }
        K = 0;
        int pre = 0;
        for (int i = 1; i <= n; ++i) id[i] = i;
        for (int i = 0; i < m; ++i) {
            if (a[i] == 0) continue;
            dfs(n - pre - pt[i] + 1, n - pre);
            pre += pt[i];
        }
        pre = 1;
        id[n] = pt[m - 1];
        int last = n;
        for (int i = 0; i < m - 1; ++i) {
            if (a[i] == 0) {
                for (int j = 0; j < pt[i]; ++j) {
                    id[n - pt[i + 1] + j + 1] = pt[m - 1] - pre;
                    ++pre;
                }
            } else {
                for (int j = 0; j < pt[i]; ++j) {
                    id[n - pt[i + 1] + j + 1] = last - pt[i] + 1 + j;
                    ++pre;
                }
                last -= pt[i];
            }
            //for (int j = 0; j < pt[i]; ++j) printf("%d ", n - pt[i + 1] + j + 1);puts("P");
        }
        //for (int i = 1; i <= n; ++i) printf("%d ", id[i]); puts("");
        dfs(n - pt[m - 1] + 1, n);
        printf("%d\n", K);
        for (int i = 0; i < K; ++i) printf("%d %d\n", u[i], v[i]);
    }
    return 0;
}

/*

*/