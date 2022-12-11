#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2025;
const int MOD = (int)1e9 + 7;

int dp[N][N];

void calc(){
   dp[0][0] = 1;
   for(int i = 1; i < N ; i ++ ){
      for(int j = 0 ; j <= i ; j ++ ){
	 if(j < i)
            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
         if(j > 0)
	    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      }
   }
}

int main(){
   fastIO;
   calc();
   int n, m;
   cin >> n >> m;
   string t;
   cin >> t;
   int bal = 0;
   int mbl = 0;
   for(char x : t){
      if(x == '(')
	bal ++ ; 
      else
        bal -- ;
      mbl = min(mbl, bal);
   }
   int answ = 0;
   int vi;
   int rem = n - m;
   for(int i = 0; i <= n - m; i ++ ){
      for(int j = 0 ; j <= n - m; j ++ ){
	if(j + mbl >= 0){
           vi = j + bal;
 	   if(vi <= rem){
	      answ = (answ + (dp[i][j] * 1ll * dp[rem][vi]) % MOD) % MOD;	   	
	   }
	}
      }
      rem --;
   }
   cout << answ;
   return 0;
}