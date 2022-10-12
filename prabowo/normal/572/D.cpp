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

int n, k;
int nambah, batas;
LL arr[300002];
LL diff[300003];
LL dp[5005][5005];

/*
LL f(int x, int y) {
    if (y > batas) return INFLL;
    if (x == k) return (y == batas) ? 0 : INFLL;
    if (dp[x][y] != -1) return dp[x][y];

    return dp[x][y] = min(diff[x*nambah + y + nambah - 1] - diff[x*nambah + y] + f(x+1, y), diff[x*nambah + y +  nambah] - diff[x*nambah + y] + f(x+1, y+1));
}
*/

int main () {
    scanf("%d %d", &n, &k);
    nambah = n / k;
    batas = n % k;

    for (int i=0; i<n; i++) {
        scanf("%I64d", &arr[i]);
    }

    sort(arr, arr+n);
    for (int i=1; i<n; i++) {
        diff[i] = abs(arr[i] - arr[i-1]);
        diff[i] += diff[i-1];
    }

    dp[k][batas] = 0;
    for (int i=0; i<batas; i++) dp[k][i] = INFLL;
    for (int i=0; i<=k; i++) dp[i][batas+1] = INFLL;

    for (int i=k-1; i>=0; i--) {
        for (int j=batas; j>=0; j--) {
            int now = i * nambah + j;
            dp[i][j] = min(diff[now + nambah - 1] - diff[now] + dp[i+1][j], diff[now + nambah] - diff[now] + dp[i+1][j+1]);
        }
    }

    printf("%I64d\n", dp[0][0]);

    return 0;

}