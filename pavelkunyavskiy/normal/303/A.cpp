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

  int n;
  scanf("%d",&n);
  if (n % 2 == 0)
    printf("-1\n");
  else{
    for (int i = 0; i < n; i++)
        printf("%d%c",i," \n"[i==n-1]);
    for (int i = 0; i < n; i++)
        printf("%d%c",i," \n"[i==n-1]);
    for (int i = 0; i < n; i++)
        printf("%d%c",(2*i)%n," \n"[i==n-1]);
  }

    
      
  TIMESTAMP(end);
  return 0;
}