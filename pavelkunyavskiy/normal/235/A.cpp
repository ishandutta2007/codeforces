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

ll gcd(ll a,ll b){
    return !b?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

ll lcm(ll a,ll b,ll c){
    return lcm(a,lcm(b,c));
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n;
  cin >> n;

  ll ans = 0;

  for (int i = max(1,n-100); i <= n;i++)
    for (int j = i; j <= n; j++)
        for (int k = j; k <= n; k++)
            ans = max(ans, lcm(i,j,k));

  cout << ans << endl;
  return 0;
}