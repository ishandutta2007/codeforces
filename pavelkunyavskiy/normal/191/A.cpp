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

int dp[26][26];

char s[200];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  memset(dp,~63,sizeof(dp));

  gets(s);
  int n;
  sscanf(s,"%d",&n);

  for (int i = 0; i < n; i++){
    gets(s);
    int l = strlen(s);
    int from = s[0] - 'a';
    int to = s[l-1] - 'a';

    for (int i = 0; i < 26; i++)
        dp[i][to] = max(dp[i][to],dp[i][from] + l);
  
    dp[from][to] = max(dp[from][to],l);
  }

  int ans = 0;
  for (int i = 0; i < 26; i++){ 
    ans = max(ans,dp[i][i]);
  }
  

  cout << ans << endl;


  return 0;
}