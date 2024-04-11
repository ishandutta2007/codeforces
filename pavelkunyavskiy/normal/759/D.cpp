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

#define TASKNAME "D"

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

const int MOD = 1000000007;

void add(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

int mul(int a, int b) {
    return (int) ((a * 1LL * b) % MOD);
}

const int MAXN = 5010;

int dp[MAXN][MAXN];
int cnk[MAXN][MAXN];
int last[26];
char s[MAXN];


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d%s", &n, s);


    cnk[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (i) add(cnk[i][j], cnk[i-1][j]);
            if (i && j) add(cnk[i][j], cnk[i-1][j - 1]);
        }

    memset(last, -1, sizeof(last));

    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
        for (int j = 0; j < 26; j++) {
            if (last[j] != -1 && j != s[i] - 'a') {
                for (int k = 2; k <= i + 1; k++) {
                    add(dp[i][k], dp[last[j]][k - 1]);
                }
            }
        }
        last[s[i] - 'a'] = i;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (last[i] != -1) {
            for (int k = 1; k <= n; k++) {
                add(ans, mul(dp[last[i]][k], cnk[n-1][k - 1]));
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}