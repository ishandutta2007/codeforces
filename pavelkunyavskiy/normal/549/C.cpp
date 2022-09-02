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

const char* ans[2] = {"Daenerys", "Stannis"};

void solve(int a, int b, int k) {
    int move = 1;
    while (a + b > k) {
        if (a + b == k + 1 && b > 0 && a > 0) {
            printf("%s\n", ans[move]);
            return;
        }
        if (b == 0 || (move == 1 && a > 0))
            a--;
        else
            b--;
        move ^= 1;
    }
    printf("%s\n", ans[b % 2]);
}

int main(){
#ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
#endif
    int k, n;
    while (scanf("%d%d",&n,&k) == 2) {
        int cnt[2];
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; i++){
            int a;
            scanf("%d",&a);
            cnt[a & 1]++;
        }
        solve(cnt[0], cnt[1], k);
    }
  return 0;
}