#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

int main(){
  fastIO;
  int n;
  cin >> n;
  int pyr[n][n];
  for(int i = 0;i < n;i ++){
    cin >> pyr[0][i];
  }
  for(int i = 1;i < n;i ++ ){
    for(int j = 0;j < n - i;j ++ ){
      pyr[i][j] = pyr[i-1][j] ^ pyr[i-1][j + 1];
    }
  }
  int dp[n][n];
  int sz;
  for(int i = 0;i < n;i ++ ){
    for(int j = i;j < n;j ++ ){
      sz = j - i;
      dp[i][j] = pyr[sz][i];
    }
  }
  int rb;
  for(int j = 2;j <= n;j ++ ){
    for(int i = 0; i+j <= n;i ++ ){
      rb = i + j - 1;
      dp[i][rb] = max(dp[i][rb],
      max(dp[i][rb-1],
      dp[i+1][rb]));
    }
  }
  int lh,rh;
  int q;
  cin >> q;
  for(int i = 0;i < q;i ++ ){
    cin >> lh >> rh;
    lh --;
    rh -- ;
    cout << dp[lh][rh] << "\n";
  }
  return 0;
}