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


int w[111000];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,l,r,a,b;
    scanf("%d %d %d %d %d",&n,&l,&r,&a,&b);

    int sumr = 0, suml = 0;

    for (int i = 0; i < n; i++){
        scanf("%d",&w[i]);
        sumr += w[i];
    }

    ll ans = 1LL<<60;

    for (int i = 0; i <= n; i++){
        int lf = i;
        int rg = n-i;
        ans = min(ans, suml * 1LL* l + sumr * 1LL* r + max(rg - lf - 1, 0) * b + max(lf - rg - 1, 0)*a);
        eprintf("%d %d " LLD"\n", l, r, ans);
        suml += w[i];
        sumr -= w[i];
    }


    printf(LLD"\n", ans);
      
    return 0;
}