#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
ll dp[N][2];
ll A[N];
ll B[N];

int main(){
  fastIO;
  int n;
  ll k;
  cin >> n >> k;
  for(int i = 1 ; i <= n; i ++ )
    dp[i][0]=dp[i][1] = (ll)1e18;
  for(int i = 1; i <= n; i ++)
    cin >> A[i];
  for(int i = 1; i <= n; i ++ )
    cin >> B[i];
  ll bi, ai;
  for(int i = 1; i <= n; i ++ ){
    if(A[i] == B[i]){
      if(k == 1){
        if(i==1) dp[i][0] = dp[i][1] = 1;
        else{
          if(dp[i-1][0] == 1) dp[i][0] = 1;
          if(dp[i-1][1] == 1) dp[i][1] = 1;
        }
      
      }
      else{
        for(int x = 0; x < 2; x ++ ){
          if(dp[i-1][x] < k) dp[i][x] = 1;
          else if(dp[i-1][x]==k){
            if(A[i] > 1) dp[i][0] = dp[i][1] = 1;
            else dp[i][x] = 1;
          }
        }
      }
    }
    else if(B[i] < A[i]){
      for(int x = 0 ; x < 2; x ++ ){
        if(dp[i-1][x] > k) continue;
        bi = B[i];
        ai = A[i];
        ai -= (bi-1);
        if(x==1){
          ai -= k;
        }
        else{
          ai -= (k - dp[i-1][0]);
        }
        ai -= (bi - 1) * 1ll * (k - 1);
        if(ai > 0)
          dp[i][0] = min(dp[i][0],ai);
        else{
          dp[i][1] = min(dp[i][1],1ll);
          dp[i][0] = min(dp[i][0],1ll);
        }
        
      }
    }
    else{
      for(int x = 0; x < 2; x ++ ){
        if(dp[i-1][x] > k) continue;
        ai = A[i];
        bi = B[i];
        bi -= (ai - 1);
        if(x == 0){
          bi -= k;
        }
        else{
          bi -= (k - dp[i-1][1]);
        }
        bi -= (ai - 1) * 1ll * (k - 1);
        if(bi > 0)
          dp[i][1] = min(dp[i][1], bi);
        else{
          dp[i][1] = min(dp[i][1],1ll);
          dp[i][0] = min(dp[i][0],1ll);
        }
      }
    }
    if(dp[i][0] > k && dp[i][1] > k){
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
  return 0;
}