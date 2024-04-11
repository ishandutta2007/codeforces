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

#define TASKNAME "E"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

int n;
int a[3100];
int cnt[3100];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
      
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] = abs(a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        int costp, costm;
        costp = 0;
        costm = 0;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                costm++;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[i])
                costp++;
//          eprintf("%d %d\n", costm, costp);
        ans += min(costm, costp);
/*      if (costm < costp)
            eprintf("%d ", -a[i]);
        else
            eprintf("%d ", a[i]);*/
    }

//      eprintf("\n");

    printf("%d\n", ans);

    return 0;
}