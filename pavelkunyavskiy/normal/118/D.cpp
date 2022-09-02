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

int dp[110][110][2];

const int MOD = 100000000;

void norm(int& ans){
    if (ans >= MOD)
        ans -= MOD;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n1,n2,k1,k2;
    cin >> n1 >> n2 >> k1 >> k2;

  dp[0][0][0] = dp[0][0][1] = 1;

  for (int sum = 0; sum <= n1+n2; sum++)
    for (int i = 0; i <= sum && i <= n1; i++){
        int j = sum - i;
        if (j > n2)
            continue;


        for (int k = 1; k <= k1 && i+k <= n1; k++){
            dp[i+k][j][1] += dp[i][j][0];
            norm(dp[i+k][j][1]);
        }

        for (int k = 1; k <= k2 && j+k <= n2; k++){
            dp[i][j+k][0] += dp[i][j][1];
            norm(dp[i][j+k][0]);
        }                               
    }

  cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;
  return 0;
}