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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m;
    scanf("%d %d",&n,&m);

    if (m == 3){
        if (n >= 5) {
            puts("-1");
            return 0;
        }
/*          if (n == 5){
            puts("0 0");
            puts("10 0");
            puts("5 5");
            puts("2 1");
            puts("8 1");
            return 0;
        } */
    }

    for (int i = 0; i < m; i++)
        printf("%d %d\n", i-m,i*i);

    for (int i = 1; i <= n-m; i++)
        printf("%d %d\n",i, -(n-m-i)*(n-m-i)-1);

      
  return 0;
}