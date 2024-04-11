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

#define TASKNAME "F"

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

int dp[105][55000];
int ndp[105][55000];

inline void add(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

int mulprec[102][1<<16];

inline int mult(int a, int b) {
    int res = a * (b & 0xffff);
    add(res, mulprec[a][b >> 16]);
    //assert(res == (a * 1LL * b) % MOD);
    return res;
}



int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    for (int i = 0; i <= 101; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            mulprec[i][j] = (int) ((i * ((ll)j << 16)) % MOD);
        }
    }


    int n, k;
    scanf("%d %d",&n, &k);
    ndp[0][k] = 1;
    vector<int> a(n);
    for (int& x : a) scanf("%d",&x);
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i && j <= n - i; j++) {
            memcpy(dp[j], ndp[j], (j * 500 + k + 1) * sizeof(int));
        }
        for (int j = 0; j <= i && j <= n - i; j++) {
            for (int q = 0; q <= j * 500 + k; q++) {
                int t = mult(j, dp[j][q]);
                add(ndp[j][q], t);
                add(ndp[j + 1][q + a[i]], dp[j][q]);
                if (j && q >= a[i]) add(ndp[j - 1][q - a[i]], t);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
        add(ans, ndp[0][i]);

    printf("%d\n", ans);
    return 0;
}