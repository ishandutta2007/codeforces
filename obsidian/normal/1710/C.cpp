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
const int P = 998244353;
const int V = 200100;
int dp[V][8][8];
char s[V];

int main() {
    while (~scanf("%s", s)) {
        int n = strlen(s);
        memset(dp, 0, sizeof(dp));
        //for (int i = 0; i < 7; ++i) dp[0][i][7] = 1;
        dp[0][0][7] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 8; ++j) {
                for (int k = 0; k < 8; ++k) {
                    for (int a = 0; a < 2; ++a) {
                        if ((k & 1) && (s[i] - '0') < a) continue;
                        for (int b = 0; b < 2; ++b) {
                            if ((k & 2) && (s[i] - '0') < b) continue;
                            for (int c = 0; c < 2; ++c) {
                                if ((k & 4) && (s[i] - '0') < c) continue;
                                int nk = 0;
                                if ((k & 1) && (s[i] - '0') == a) nk |= 1;
                                if ((k & 2) && (s[i] - '0') == b) nk |= 2;
                                if ((k & 4) && (s[i] - '0') == c) nk |= 4;
                                //if (dp[i][0][k] == 0 && dp[i][1][k] == 0 && dp[i][2][k] == 0) continue;
                                if (dp[i][j][k] == 0) continue;
                                //printf("DP %d %d %d %d %d %d %d %d\n", i, j, k, dp[i][j][k], a, b, c, nk);
                                if (a == b && b == c) {
                                    dp[i + 1][j][nk] += dp[i][j][k];
                                    dp[i + 1][j][nk] %= P;
                                } else {
                                    int nj = j;
                                    if (a == b) nj |= 1;
                                    if (a == c) nj |= 2;
                                    if (b == c) nj |= 4;
                                    dp[i + 1][nj][nk] += dp[i][j][k];
                                    dp[i + 1][nj][nk] %= P;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int k = 0; k < 8; ++k) {
            ans += dp[n][7][k];
            ans %= P;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
101
1110
11011111101010010
*/