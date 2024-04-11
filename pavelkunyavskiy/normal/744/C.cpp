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

#define TASKNAME "C"

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

const int MAXS = 150;
const int MAXN = 16;

int dp[1 << MAXN][MAXS];

int type[MAXN];
int r[MAXN];
int b[MAXN];

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d", &n);
    int totr, totb;
    totr = totb = 0;
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        type[i] = c == 'B';
        scanf("%d%d", &r[i], &b[i]);
        totr += r[i];
        totb += b[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < (1 << n); i++) {
        int rs, bs;
        rs = bs = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if (type[j]) {
                    bs++;
                } else {
                    rs++;
                }
            }
        }
        for (int j = 0; j < MAXS; j++) {
            if (dp[i][j] == -1) continue;

            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) continue;
                int saver = min(r[k], rs);
                int saveb = min(b[k], bs);
                assert(j + saver < MAXS);
//                fprintf(stderr, "mask = %d, j = %d, buy = %d, saver = %d, saveb = %d\n", i, j, k, saver, saveb);
                dp[i | (1 << k)][j + saver] = max(dp[i | (1 << k)][j + saver], dp[i][j] + saveb);
            }
        }
    }

    int ans = max(totr, totb);

    for (int i = 0; i < MAXS; i++) {
        int res = dp[(1 << n) - 1][i];
        if (res == -1) continue;
        ans = min(ans, max(totr - i, totb - res));
    }

    printf("%d\n", ans + n);


    return 0;
}