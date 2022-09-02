#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1100000;

int deg[MAXN];

int n,m;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  scanf("%d %d",&n,&m);
  int a,b;
  for (int i = 0; i < m; i++){
    scanf("%d %d",&a,&b);
    --a,--b;
    deg[a]++;
    deg[b]++;
  }

  ll ans = - n * 1LL * (n-1) * 1LL * (n-2);
  ans /= 6;

  for (int i = 0; i < n; i++){
    ans += deg[i] * 1LL * (deg[i]-1)/2;
    ans += (n - deg[i] - 1) * 1LL * (n - deg[i] - 2)/2;
  }

  assert(ans % 2 == 0);
  assert(ans >= 0);
  ans /= 2;
  cout << ans << endl;


      
  return 0;
}