#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = 5101;
int dp[N][N / 2][2];
int a[N];

void upd(int &a, int vl){
  a = min(a, vl);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int k = (n + 1)/2;
  for(int i = 1;i <= n; i ++ )
    cin >> a[i];
  for(int i = 0;i <= n;i ++ ){
    for(int j = 0;j <= k;j ++ ){
      for(int x = 0; x < 2; x ++ ){
        dp[i][j][x] = (int)2e9; 
      }
    }
  }
  dp[0][0][0] = 0;
  dp[1][1][1] = 0;
  for(int i = 0;i < n;i ++ ){
    for(int j = 0;j <= k;j ++ ){
      upd(dp[i + 1][j][0], dp[i][j][0]);
      upd(dp[i + 1][j][0], dp[i][j][1] + max(0, a[i + 1] - a[i] + 1));
      upd(dp[i + 2][j + 1][1], dp[i][j][0] + max(0, a[i + 1] - a[i + 2] + 1));
      upd(dp[i + 2][j + 1][1], dp[i][j][1] + max(0, a[i + 1] - min(a[i], a[i + 2]) + 1));
    }
  }
  for(int i = 1;i <= k;i ++ ){
    cout << min(dp[n][i][0], dp[n][i][1]) << " ";
  }
  return 0;
}