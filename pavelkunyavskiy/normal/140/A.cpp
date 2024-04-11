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

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    ld n,R,r;
    cin >> n >> R >> r;
    if (n == 1){
        if (r <= R + (1e-9))
            cout <<"YES\n";
        else
            cout <<"NO\n";
        return 0;
    }

    if (r < (R - r)*sin (M_PI/n) + (1e-9))
        cout << "YES\n";
    else
        cout << "NO\n";
  return 0;
}