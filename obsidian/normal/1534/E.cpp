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
int a[V];

bool check(int n, int K, int m) {
    int total = m * K - n;
    if (total < 0 || total % 2 == 1) return false;
    for (int i = 1; i <= n; ++i) a[i] = 1;
    for (int i = 1; total > 0; i = i % n + 1) {
        a[i] += 2;
        total -= 2;
        if (a[i] > m) return false;
    }
    return true;
}

int id[V];
bool cmp(int x, int y) {
    return a[x] > a[y];
}

int n, K, m, y;
int main() {
    while (~scanf("%d%d", &n, &K)) {
        m = -1;
        for (int i = 1; i <= n; ++i) {
            if (check(n, K, i)) {m = i; break;}
        }
        if (m == -1) {
            puts("-1");
            fflush(stdout);
            continue;
        }
        //printf("M %d\n", m);
        //for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) id[j] = j;
            sort(id + 1, id + n + 1, cmp);
            printf("?");
            for (int j = 1; j <= K; ++j) {
                printf(" %d", id[j]);
                a[id[j]]--;
            }
            puts("");
            fflush(stdout);
            scanf("%d", &y);
            ans ^= y;
        }
        printf("! %d\n", ans);
        fflush(stdout);
    }
    return 0;
}

/*

*/