//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;


const int MAXN = 510;

int dp[MAXN][MAXN];
int a[MAXN];

int solve(int l, int r) {
    if (l > r) return 0;
    int &ans = dp[l][r];
    if (ans != -1) return ans;
    if (l == r) return ans = 1;
    ans = solve(l + 1, r) + 1;
    for (int i = l + 1; i <= r; i++)
        if (a[l] == a[i])
            ans = min(ans, solve(l + 1, i - 1) + solve(i + 1, r) + (i == l + 1));
    return ans;
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, n - 1));
#ifdef LOCAL
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            fprintf(stderr, "-%c", " \n"[j == n - 1]);
        for (int j = i; j < n; j++)
            fprintf(stderr, "%d%c", solve(i, j), " \n"[j == n - 1]);
    }
#endif
    return 0;
}