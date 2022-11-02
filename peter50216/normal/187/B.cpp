#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

typedef long long LL;
typedef long double LD;

#define pb push_back
#define mp make_pair
#define sz(A) int((A).size())
#define y1 Y1
#define y2 Y2

const int INF = int(1e9), N = 65;

int timer[N][N][N], dp[N][N][N];

int main() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                scanf("%d", &timer[i][j][k]);
                for (int f = 1; f <= n; f++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                    timer[i][j][k] = min(timer[i][j][k], timer[i][j][f] + timer[i][f][k]);      
    }

    for (int iter = 0; iter < n; iter++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dp[iter][j][k] = INF;       

    for (int i = 0; i < m; i++) 
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dp[0][j][k] = min(dp[0][j][k], timer[i][j][k]);

    for (int iter = 1; iter < n; iter++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                dp[iter][i][j] = dp[iter - 1][i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    for (int k = 1; k <= n; k++) {
                        if (k != i && k != j)   
                            dp[iter][i][j] = min(dp[iter][i][j], dp[iter - 1][i][k] + dp[0][k][j]);
                    }
                }
            }
    }

    for (int i = 0; i < r; i++) {
        int s, t, k;
        scanf("%d%d%d", &s, &t, &k);        
        k = min(n - 1, k);
        printf("%d\n", dp[k][s][t]);
    }
                                                                                                                
    return 0;
}