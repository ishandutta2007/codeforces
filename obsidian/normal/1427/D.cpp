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
const int V = 60;
int a[V], n, b[V], R[V];
vector<int> ans[V];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int m = 0;
        while (true) {
            for (int i = n; i > 0; --i) {
                if (i != n && a[i] + 1 == a[i + 1]) R[i] = R[i + 1] + 1;
                else R[i] = 1;
            }
            //for (int i = 1; i <= n; ++i) printf("%d ", R[i]); puts("R");
            int x = -1, y = -1;
            for (int i = 1; i <= n && x == -1; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    if (a[i] == a[j] + 1){
                        x = i, y = j;
                        break;
                    }
                }
            }
            if (x == -1) break;
            ans[m].clear();
            if (x > 1) ans[m].PB(x - 1);
            ans[m].PB(R[x]);
            ans[m].PB(y - x - R[x] + 1);
            if(y < n) ans[m].PB(n - y);
            int cur = n;
            int pre = 0;
            for (int i = 0; i < ans[m].size(); ++i) {
                for (int j = 0; j < ans[m][i]; ++j) b[cur--] = a[pre + ans[m][i] - j];
                pre += ans[m][i];
            }
            for (int i = 1; i <= n; ++i) a[i] = b[i];
            //for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("A");
            m++;
        }
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) {
            printf("%d", ans[i].size());
            for (int j = 0; j < ans[i].size(); ++j) printf(" %d", ans[i][j]); puts("");
        }
    }
    return 0;
}

/*
4
3 1 2 4
6
6 5 4 3 2 1
1
1
*/