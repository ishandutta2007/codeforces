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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int ans;
    ans = 0;
    int n;
    scanf("%d",&n);
    int cur = 0;
    int lastt = 0;

    for (int i = 0; i < n; i++){
        int t,x;
        scanf("%d %d",&t,&x);
        cur = max(0,cur - (t - lastt));
        cur += x;
        ans = max(ans,cur);
        lastt = t;
    }

    printf("%d %d\n",lastt + cur,ans);      
  TIMESTAMP(end);
  return 0;
}