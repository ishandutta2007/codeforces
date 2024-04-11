#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;
#define FOR(i , x , n) for(int i = (x) ; i < (n) ; i++)
#define FORR(i , x , n) for(int i = (x) ; i <= (n) ; i++)
#define REP(i , x , n) for(int i = (x) ; i > (n) ; i--)
#define REPP(i ,x , n) for(int i = (x) ; i >= (n) ; i--)
const int MAXN = 1000 + 50;
const long long LLMAX = 0x7fffffffffffffffLL;
const long long LLMIN = 0x8000000000000000LL;
const int INF = 0x7fffffff;
const int IMIN = 0x80000000;
#define eps 1e-4
const int MOD = (int)1e9 + 7;
typedef long long LL;
int dp[MAXN][MAXN][2] , a[MAXN][MAXN][2] , n ;
int main()
{
    int x ,  r;
    bool ok;
    while(~scanf("%d" , &n))
    {
        ok = false;
        FOR(i ,0 , n)FOR(j ,0 , n)
        {
            scanf("%d" , &x);
            if(x == 0)
            {
                ok = true;
                r = i ; x = 10;
            }
            while(x % 2 == 0)
            {
                x /= 2;
                dp[i][j][0] ++;
            }
            while(x % 5 == 0)
            {
                x /= 5;
                dp[i][j][1]++;
            }
            FOR(k , 0 , 2)a[i][j][k] = dp[i][j][k];
        }
        FOR(i , 1 , n)FOR(j , 0 , 2)
        {
            dp[0][i][j] += dp[0][i - 1][j];
            dp[i][0][j] += dp[i - 1][0][j];
        }
        FOR(i , 1 , n)FOR(j , 1 , n)FOR(k , 0 ,2)
        {
            dp[i][j][k] += min(dp[i - 1][j][k] , dp[i][j - 1][k]);
        }
        int k = dp[n - 1][n - 1][1] < dp[n - 1][n - 1][0] ;
        if(ok)
        {
            if(dp[n - 1][n - 1][k] > 1)
            {
                printf("1\n");
                FORR(i , 1 , r)printf("D");
                FOR(i , 0 , n - 1)printf("R");
                FOR(i , r + 1 , n)printf("D");
                continue;
            }
        }
        printf("%d\n" , dp[n - 1][n - 1][k]);
        int i = n - 1 , j = n - 1;
        char s[MAXN * 3];
        int len = 0;
        while(i != 0||j != 0)
        {
            if(i > 0&&dp[i - 1][j][k] + a[i][j][k] == dp[i][j][k])
            {
                s[len++] = 'D';
                i--;
            }
            else
            {
                s[len++] = 'R';
                j--;
            }
        }
        REPP(i ,len - 1 , 0)printf("%c" , s[i]);
        printf("\n");
    }

    return 0;
}