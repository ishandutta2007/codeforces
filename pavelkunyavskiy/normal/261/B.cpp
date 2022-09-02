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

ll dp[55][55];
ll dp2[55][55];
ll c[55][55];

int n;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    dp[0][0] = 1;
    scanf("%d",&n);

    c[0][0] = 1;
    for (int i = 0; i <= 50; i++)
	    for (int j = 0; j <= 50; j++){
	    	if (i) c[i][j] += c[i-1][j];
	    	if (i && j) c[i][j] += c[i-1][j-1];
	    }


    for (int i = 0; i < n; i++){
    	int x;
    	scanf("%d",&x);
    	for (int j = 0; j <= 50; j++)
	    	for (int k = 0; k <= 50; k++){
	    		if (k + x <= 50)
	    			dp2[j+1][k+x] += dp[j][k];
	    		dp2[j][k] += dp[j][k];
	    	}
	    memcpy(dp,dp2,sizeof(dp));
	    memset(dp2,0,sizeof(dp2));
    }

    for (int i = 0; i <= 50; i++)
    	for (int j = 1; j <= 50; j++)
    		dp[i][j] += dp[i][j-1];

	int p;
	scanf("%d",&p);

	double ans = 0;

	for (int i = 1; i <= n; i++){
		
		ans += dp[i][p] * 1.0 / c[n][i];
	}

	cout.precision(15);
	cout << fixed << ans << endl;
      
    return 0;
}