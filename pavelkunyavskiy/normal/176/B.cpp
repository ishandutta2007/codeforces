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

#define ADD(x,y) if ((x += (y)) >= MOD) x -= MOD

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

string s,t;
int k,n;

int dp[1100];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    getline(cin,s);
    getline(cin,t);
    scanf("%d",&k);

    n = s.size();

    dp[0] = 1;

    for (int i = 0; i < k; i++){
        int sum = 0;
        for (int j = 0; j < n; j++)
            ADD(sum,dp[j]);
        for (int j = 0; j < n; j++){
            dp[j] = MOD - dp[j];
            ADD(dp[j],sum);
        }
    }          


    int ans = 0;

    for (int i = 0; i < n; i++){
        if (s == t)
            ADD(ans,dp[i]);
        rotate(s.begin(),s.begin()+1,s.end());
    }

    cout << (ans + MOD) % MOD << endl;
    
    return 0;
}