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

const int MAXN = 360400;

ll dp[MAXN*4];

ll a,b;
int k;

int g;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin >> a >> b>> k;

    g = 1;
    for (int i = 2; i <= k; i++)
    	g = g/__gcd(g,i)*i;

    {
      ll tmp = (b/g)*g;
      a -= tmp;
      b -= tmp;
    }

    for (int i = b+1; i <= b + 3*g; i++){
    	dp[i] = dp[i-1]+1;
    	for (int j = 2; j <= k; j++)
    		if (i - (i%j) >= b)
	    		dp[i] = min(dp[i], dp[i-(i%j)] + 1);
    }


    ll tmp = ((a-b)/g);
    if (tmp) tmp--;
    ll ans = tmp * (dp[b+2*g] - dp[b+g]);
    a -= tmp * g;
    ans += dp[a];
    //cerr << a << endl;

    cout << ans << endl;  
    return 0;
}