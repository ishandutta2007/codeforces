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


const int MAXN = 1e6+10;

int used[MAXN];


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        used[x] = 1;
    }

    const int MAXV = 1e6;
    int cnt = 0;
    for (int i = 1; i <= MAXV; i++)
        if (used[i] && !used[MAXV - i + 1])
            used[MAXV - i + 1] = 2;
        else if (used[i] == 1&& used[MAXV - i + 1] == 1)
            cnt++;
    assert(cnt % 2 == 0);
    cnt /= 2;
    for (int i = 1; i <= MAXV && cnt; i++)
        if (!used[i] && !used[MAXV - i + 1])
            used[i] = used[MAXV - i + 1] = 2, cnt--;
    cnt -= 2;

    int anscnt = 0;
    for (int i = 1; i <= MAXV; i++)
        if (used[i] == 2)
            anscnt++;
    printf("%d\n", anscnt);
    for (int i = 1; i <= MAXV; i++)
        if (used[i] == 2)
            printf("%d ", i);
    printf("\n");      
    return 0;
}