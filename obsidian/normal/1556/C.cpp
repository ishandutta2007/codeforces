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
int a[V];
LL s[V][V], L[V][V];
int n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) s[i][i] = a[i], L[i][i] = 0;
            else s[i][i] = -a[i], L[i][i] = -a[i];
            for (int j = i + 1; j <= n; ++j) {
                if (j % 2 == 1) s[i][j] = s[i][j - 1] + a[j];
                else s[i][j] = s[i][j - 1] - a[j];
                L[i][j] = min(L[i][j - 1], s[i][j]);
            }
        }
        LL ans = 0;
        for (int i = 1; i <= n; i += 2)  {
            for (int j = i + 1; j <= n; j += 2) {
                //printf("D %d %d %d %d %I64d %I64d\n", i, j, a[i], a[j], L[i + 1][j - 1], ans);
                if (j == i + 1) {
                    ans += min(a[i], a[j]);
                    continue;
                }
                LL M = L[i + 1][j - 1];
                LL wi = a[i];
                LL wj = a[j];
                if (s[i + 1][j - 1] < 0) wi += s[i + 1][j - 1], M -= s[i + 1][j - 1];
                else if (s[i + 1][j - 1] > 0) wj -= s[i + 1][j - 1];
                wi = min(wi, wi + M + 1);
                wj = min(wj, wj + M + 1);
                LL D = min(wi, wj);
                //printf("%I64d %I64d %I64d %I64d %I64d\n", wi, wj, s[i + 1][j - 1], D, M);
                if (D < 0) continue;
                ans += D;
                //if (M >= 0) ans += D;
                //else ans += max(0LL, min(D, a[i] + M + 1));
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
4 1 2 3 1
6
1 3 2 1 2 4
6
1 1 1 1 2 2
*/