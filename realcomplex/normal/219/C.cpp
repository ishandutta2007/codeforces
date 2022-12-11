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

const int N = (int)5e5 + 9;
const int K = 26;

int dp[N][K];
int pp[N][K];

int main(){
  fastIO;
  memset(dp, 1244217215, sizeof dp);
  int n,k;
  cin >> n >> k;
  for(int j = 0;j < k;j ++ )
    dp[0][j] = 0; 
  char nex; 
  int real;
  for(int i = 1;i <= n;i ++ ){
    cin >> nex;
    real = nex - 'A';
    int i1 = -1, i2 = -1;
    for(int j = 0;j < k;j ++ ){
      if(i1 == -1 or dp[i - 1][j] < dp[i - 1][i1]){
        i2 = i1;
        i1 = j;
      }
      else if(i2 == -1 or dp[i - 1][j] < dp[i - 1][i2]){
        i2 = j;
      }
    }
    for(int j = 0;j < k;j ++ ){
      if(j == real){
        if(j == i1) dp[i][j] = dp[i - 1][i2], pp[i][j] = i2;
        else dp[i][j] = dp[i - 1][i1], pp[i][j] = i1;
      }
      else{
        if(j == i1) dp[i][j] = dp[i - 1][i2] + 1, pp[i][j] = i2;
        else dp[i][j] = dp[i - 1][i1] + 1, pp[i][j] = i1;
      }
    }
  }
  int ix = 0;
  for(int i = 0;i < k;i ++ ){
    if(dp[n][i] < dp[n][ix])
      ix = i;
  }
  cout << dp[n][ix] << "\n";
  string rev;
  for(int j = n-1;j >= 0; j -- ){
    rev.push_back(char(ix + 'A'));
    ix = pp[j + 1][ix];
  }
  reverse(rev.begin(), rev.end());
  cout << rev;
  return 0;
}