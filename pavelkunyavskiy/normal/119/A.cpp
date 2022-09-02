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

int gcd(int a,int b){
    if (!a || !b)
        return a+b;
    return gcd(b,a%b);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int a,b,n;
  cin >> a >> b >> n;
  int h = 1;

  while (true){
    int need = 0;
    if (h == 1)
        need = gcd(n,a);
    else
        need = gcd(n,b);
    if (need > n)
        break;
    n -= need;
    h ^= 1;
  }

  cout << h << endl;


  return 0;
}