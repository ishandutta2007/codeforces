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

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;


unsigned int value[110000];
unsigned int value2[110000];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  int n,k;
  scanf("%d %d",&n,&k);

  for (int i = 0; i < n; i++){
    unsigned int a,b,c,d;
    scanf("%u.%u.%u.%u",&a,&b,&c,&d);
    value[i] = (a<<24) | (b << 16) | (c << 8) | d;
  }

  for (int i = 31; i > 0; i--){
    unsigned mask = 0xffffffff ^ ((1u<<i)-1);
    for (int j = 0; j < n; j++)
        value2[j] = value[j] & mask;
    sort(value2,value2+n);
    if (unique(value2,value2+n) - value2 == k){
        printf("%u.%u.%u.%u",(mask >> 24) & 0xff, (mask >> 16) & 0xff,(mask >> 8) & 0xff,mask & 0xff);
        return 0;
    }
  }

  printf("-1\n");      
  TIMESTAMP(end);
  return 0;
}