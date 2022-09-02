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
    ll n;
    cin >> n;
    ll minv,maxv;
    minv = (1LL<<60LL);
    maxv = -minv;


    for (int i = 1; i*i <= n; i++){
        if (n % i != 0)
            continue;
        for (int I = 0; I < 2; I++){
            int a = i;
            if (I) a = n/i;
            int n1 = n / a;
            for (int j = 1; j*j <= n1; j++){
                if (n1 % j) continue;
                int b = j;
                int c = n1 / j;
                ll val = (a+1)*1LL*(b+2)*1LL*(c+2);
                minv = min(minv,val);
                maxv = max(maxv,val);
            }
        }
    }

    cout << minv - n <<" "<<maxv - n << endl;
  return 0;
}