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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

int a[4100];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n;
    scanf("%d",&n);
    n *= 2;

    for (int i = 0; i < n; i++){
        scanf(" %*d.%d",&a[i]);
//          eprintf("%d\n", a[i]);
    }

    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        cnt += (a[i] == 0);
    }

    int ans = 1<<30;

    for (int i = 0; i <= cnt && i <= n/2; i++)
        if (cnt - i <= n/2) {
            ans = min(ans, abs(sum - 1000*(n/2-i)));
        }

    printf("%d.%03d\n",ans/1000, ans % 1000);
    return 0;
}