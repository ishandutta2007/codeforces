#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x) - x.begin())
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SYNC ios_base::sync_with_stdio(0)
#define kita using
#define emang namespace
#define ganteng std

kita emang ganteng;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n, m;
char s[505][505];
LL dp[505][505][2];
/*
LL f(int x, int y, int z) {
    if (x == n || y == m) return 0;
    if (s[x][y] != s[n-(z+1)][m-(x+y)+(z-1)]) return 0;
    if ((n + m >> 1) - 1 == x + y) return (x <= n-z-1 && y <= m-x-y+z-1);
    if (dp[x][y][z] != -1) return dp[x][y][z];
    return dp[x][y][z] = (f(x+1, y, z) + f(x+1, y, z+1) + f(x, y+1, z) + f(x, y+1, z+1)) % MOD;
}
*/
int main () {
    scanf("%d %d", &n, &m);
    gets (s[0]);

    FOR (i, 0, n) gets(s[i]);

    int now = 0;
    for (int z=n-1; z>=0; z--) {
        now = 1 - now;
        for (int x=n-1; x>=0; x--) {
            int batas = (n + m >> 1) - 1 - x;
            for (int y=batas; y>=0; y--) {
                if (s[x][y] != s[n-(z+1)][m-(x+y)+(z-1)]) dp[x][y][now] = 0;
                else if (y == batas) dp[x][y][now] = (x <= n-z-1 && y <= m-x-y+z-1);
                else dp[x][y][now] = (dp[x+1][y][now] + dp[x+1][y][1-now] + dp[x][y+1][now] + dp[x][y+1][1-now]) % MOD;
            }
        }
    }

    printf("%I64d\n", dp[0][0][now]);

    return 0;
}