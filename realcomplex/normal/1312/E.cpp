#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
int red[N][N];
int a[N];
int dp[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      red[i][j]=-1;
    }
  }
  for(int i = 1; i <= n; i ++ )
    red[i][i]=a[i];
  int j;
  for(int len = 2; len <= n; len ++ ){
    for(int i = 1; i + len - 1 <= n; i ++ ){
      j = i + len - 1;
      for(int k = i; k < j; k ++ ){
        if(red[i][k] != -1 && red[k + 1][j] != -1 && red[i][k] == red[k + 1][j]){
          red[i][j] = red[i][k] + 1;
        }
      }
    }
  }
  dp[0]=0;
  for(int i = 1; i <= n; i ++ ){
    dp[i]=dp[i-1] + 1;
    for(int j = i; j >= 1; j -- ){
      if(red[j][i] != -1)
        dp[i]=min(dp[i],dp[j-1]+1);
    }
  }
  cout << dp[n];
  return 0;
}