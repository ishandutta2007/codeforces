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

#define TASKNAME "A"

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


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n;
    scanf("%d",&n);
    if (n < 4) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (n % 2 == 0) {
        printf("3 * 4 = 12\n");
        printf("2 * 12 = 24\n");
        printf("1 * 24 = 24\n");
        for (int i = 5; i < n; i += 2) {
            printf("%d - %d = 1\n", i + 1, i);
            printf("1 * 24 = 24\n");
        }
    } else {
        printf("5 + 1 = 6\n");
        printf("4 * 6 = 24\n");
        printf("3 - 2 = 1\n");
        printf("1 * 24 = 24\n");
        for (int i = 6; i < n; i += 2) {
            printf("%d - %d = 1\n", i + 1, i);
            printf("1 * 24 = 24\n");
        }
    }

      
  return 0;
}