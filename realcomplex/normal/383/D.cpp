#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int MX = (int)1e4 + 11;
const int N = 1005;
const int MOD = (int)1e9 + 7;

int dp[N][MX * 2];

void add(int &a, int b){
  a += b;
  a %= MOD;
  a += MOD;
  a %= MOD;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int a;
  dp[0][MX] ++ ;
  int ans = 0;
  for(int i = 1;i <= n;i ++ ){
    cin >> a;
    for(int j = 0;j < MX * 2;j ++ ){
      if(j + a < MX * 2){
        add(dp[i][j], dp[i-1][j + a]);
      }
      if(j - a >= 0){
        add(dp[i][j], dp[i-1][j - a]);
      }
    }
    add(ans, dp[i][MX]);
    add(dp[i][MX], 1);
  }
  cout << ans;
  return 0;
}