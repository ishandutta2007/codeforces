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


int a[1100];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n;
    scanf("%d",&n);

    for (int i = 0; i < 2*n-1; i++)
        scanf("%d",&a[i]);

    int cnt = 0;
    for (int i = 0; i < 2*n-1; i++){
        if (a[i] < 0)
            cnt++, a[i] = -a[i];
    }

    if (cnt % 2 == 0 || cnt % 2 == n % 2)
        cnt = 0;
    else
        cnt = 1;

    sort(a,a+2*n-1);

    int res = 0;
    for (int i = cnt; i < 2*n-1; i++)
        res += a[i];
    for (int i = 0; i < cnt; i++)
        res -= a[i];

    printf("%d\n",res);
      
    TIMESTAMP(end);
    return 0;
}