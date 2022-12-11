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

const int MOD = (int)1e9 + 7;
const int N = 5005;
char s[N];
char t[N];
int dp[N][N];

void add(int &a, int b){
  a += b;
  a %= MOD;
}

int main(){
  fastIO;
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  int ans = 0;
  for(int i = 0;i < n;i ++ ){
    for(int j = 0;j < m;j ++ ){
      if(a[i] == b[j]){
        add(dp[i + 1][j + 1], 1 + dp[i][j] + dp[i + 1][j]);
      }
      else{
        add(dp[i + 1][j + 1], dp[i + 1][j]);
      }
    }
    add(ans, dp[i + 1][m]);
  }
  cout << ans;
  return 0;
}