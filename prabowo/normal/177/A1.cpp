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

int n;
int arr[105][105];
bool uda[105][105];
int main () {
    scanf("%d", &n);
    FOR (i, 0, n) FOR (j, 0, n) scanf("%d", &arr[i][j]);

    int ans = 0;
    FOR (i, 0, n) {
        if (!uda[i][i]) uda[i][i] = 1, ans += arr[i][i];
        if (!uda[i][n-i-1]) uda[i][n-i-1] = 1, ans += arr[i][n-i-1];
        if (!uda[i][n >> 1]) uda[i][n >> 1] = 1, ans += arr[i][n >> 1];
        if (!uda[n >> 1][i]) uda[n >> 1][i] = 1, ans += arr[n >> 1][i];
    }

    printf("%d\n", ans);

    return 0;
}