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

typedef long long ll;
typedef long double ld;


const int MAXN = 110000;
int a[MAXN];

ll gcd(ll a,ll b){
    return b ? gcd(b, a%b) : a;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
    scanf("%d",&a[i]);
  sort(a,a+n);

  ll total = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++){
    total += a[i] * 1LL*(2*i+1) - 2LL*sum;
    sum += a[i];
  }
  ll g = gcd(total, n);

  printf(LLD" "LLD"\n", total / g, n / g);
  TIMESTAMP(end);
  return 0;
}