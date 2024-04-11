#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cassert>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
  #define LLD "%lld"
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define LLD "%I64d"
  #define eprintf(...) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int a[110000];

int main(){
  #ifdef LOCAL  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);
  if (n%2 == 0){
    cout << 0 << endl;
    return 0;
  }
  for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
  
  int64 val = 1LL<<60LL;
  for (int i=0;i<n;i+=2)
    val = min(val,a[i]*1LL);
  val = min(val,(m/((n+1)/2))*1LL*k);
  cout << val << endl;  
  return 0;
}