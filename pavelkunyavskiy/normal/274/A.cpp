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

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;


const int MAXN = 110000;

int a[MAXN];
set<int> s;

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  int n,k;
  scanf("%d %d",&n,&k);

  for (int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  if (k == 1){
    printf("%d\n",n);
    return 0;
  }

  sort(a,a+n);

  for (int i = 0; i < n; i++)
    if (a[i] % k != 0 || !s.count(a[i]/k)){
        s.insert(a[i]);
    }
        

  printf("%d\n",s.size());

      
  return 0;
}