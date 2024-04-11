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

int a[1100];
int res;

int vals[2][20100];

const int MAXV = 10010;

int _temp[2][20100];

inline void add(int& a, int b){
    if ((a += b) >= MOD) a -= MOD;
}

void solve2(int l, int r, int dir, int* to){
    int* ind = _temp[0] + MAXV;
    int* outd = _temp[1] + MAXV;
    for (int i = -MAXV; i <= MAXV; i++)
        ind[i] = !i, outd[i] = to[i] = 0;
    for (int i = l; i != r; i += dir) {
        for (int j = -MAXV + a[i]; j <= MAXV; j++)
            add(outd[j - a[i]], ind[j]);
        for (int j = -MAXV; j <= MAXV - a[i]; j++)
            add(outd[j + a[i]], ind[j]);

        for (int j = -MAXV; j <= MAXV; j++)
            add(to[j], outd[j]), ind[j] = 0;
        swap(ind, outd);        
    }
}

void solve(int l, int r){
    if (r - l == 1) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);

    solve2(m-1, l-1, -1, vals[0] + MAXV);
    solve2(m, r, 1, vals[1] + MAXV);     

    for (int i = -MAXV; i <= MAXV; i++)
        res = (res + vals[0][i + MAXV] * 1LL * vals[1][-i + MAXV]) % MOD;
    return ;
}




int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n;
    while (scanf("%d", &n) == 1){
        res = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        solve(0, n);
        printf("%d\n", res);
    }

      
  return 0;
}