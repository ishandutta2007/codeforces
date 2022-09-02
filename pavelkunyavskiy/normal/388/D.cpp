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

ll encode(int cnt, int n, int pos){
    return (n * 40LL + cnt) * 40LL + pos;
}

map<ll, int > dp;
int pow2[110];

int calc(int cnt, int n, int pos){
    if (pos == -1) return 1;
//  eprintf("%d %d %d\n", cnt, n, pos);
    ll code = encode(cnt, n, pos);
    if (dp.count(code)) return dp[code];
    int& res = dp[code];

    if (n & (1<<pos)) {
        int ans1 = (pow2[cnt] * 1LL * calc(cnt, (1<<pos) - 1, pos - 1)) % MOD;
        int ans2 = ((cnt == 0) ? 0LL : ((pow2[cnt] * 1LL * calc(cnt, n ^ (1<<pos), pos - 1)) % MOD));
        int ans3 = calc(cnt + 1, n ^ (1<<pos), pos - 1);
        return res = ((ll(ans1) + ll(ans2) + ll(ans3)) % MOD);
    } else {
        int ans1 = (pow2[cnt] * 1LL * calc(cnt, n, pos - 1)) % MOD;
        return res = ans1;
    }
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    pow2[0] = 1;
    pow2[1] = 1;
    for (int i = 2; i < 110; i++)
        pow2[i] = (pow2[i-1] * 2) % MOD;

    int k;
    while (scanf("%d", &k) == 1)
        printf("%d\n", calc(0, k, 30));      
    return 0;
}