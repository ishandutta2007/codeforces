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

ll f[100];
int rasl[100];

ll dp[90][2];

const int MFIB = 86;



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  f[0] = 1;
  f[1] = 2;
  for (int i = 2; i <= MFIB; i++)
    f[i] = f[i-1] + f[i-2];
 
  assert(f[MFIB] >= 1000LL*1000LL*1000LL*1000LL*1000LL*1000LL);

  int t;
  scanf("%d",&t);

  for (;t --> 0;){
    ll n;
    cin >> n;
    for (int i = MFIB; i >= 0; --i)
        if (n >= f[i])
            rasl[i] = 1, n -= f[i];
        else
            rasl[i] = 0;

    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 1 - rasl[0];
    for (int i = 1; i <= MFIB; i++){
        for (int j = 0; j < 2; j++){
            if (rasl[i] + j == 0){
                dp[i][j] = dp[i-1][0];
                continue;
            }
            if (rasl[i] + j < 2)
                dp[i][j] = dp[i-1][0];
            if (i >= 2 && !rasl[i-1])
                dp[i][j] += dp[i-2][1];
        }
//          cerr << f[i] <<" : "<<dp[i][0] <<" "<<dp[i][1] << endl;
    }
    cout << dp[MFIB][0] << endl;    
  }             

  

  

  return 0;
}