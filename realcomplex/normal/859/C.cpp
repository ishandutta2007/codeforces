#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 52;
int dp[N][2]; // 0 - token holder, 1 - other

int main(){ 
   int n;
   cin >> n;
   int a[n];
   int s = 0;
   for(int i = 0 ; i < n; i ++ ){
      cin >> a[i];
   }
   for(int i = n - 1; i >= 0 ; i -- ){
      s += a[i];
      dp[i][0] = max(a[i] + dp[i + 1][1], dp[i + 1][0]);
      dp[i][1] = s - dp[i][0];
   }
   cout << s - dp[0][0] << " " << dp[0][0];
   return 0;
}