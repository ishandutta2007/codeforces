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

const int MOD = 1000000007;

ll pow(ll a,ll b){
    if (b == 0)
        return 1;
    if (b & 1)
        return (pow(a,b-1)*a)%MOD;
    ll temp = pow(a,b/2);
    return (temp*temp)%MOD;
}

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  ll n;
  cin >> n;

  if (n == 0){
    cout << 1 << endl;
    return 0;
  }

  cout << (pow(2LL,n-1)*1LL*(1+pow(2LL,n)))%MOD << endl;

  return 0;
}