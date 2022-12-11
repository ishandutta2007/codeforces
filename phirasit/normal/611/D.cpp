#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;
const int mod = 1000000007;

int pos[N][N];
int sum[N][N];
int dp[N][N];
int idx[N];

string str;
int n;

int gap;
int cmp(int a, int b) {
  if(gap == 0) {
    return str[a] < str[b];
  }
  if(str[a] != str[b]) return str[a] < str[b];
  if(a >= n-gap or b >= n-gap) return a > b;
  return pos[gap-1][a+1] < pos[gap-1][b+1];
}
int main() {

  cin >> n >> str;
  
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n-i;j++) {
      idx[j] = j;
    }
    gap = i;
    sort(idx, idx + n-i, cmp);
    pos[i][idx[0]] = 0;
    for(int j = 1;j < n-i;j++) {
      pos[i][idx[j]] = pos[i][idx[j-1]] + cmp(idx[j-1], idx[j]);
    }
  }

  dp[0][n-1] = 1;
  for(int i = n-1;i > 0;i--) {
    for(int j = 1;j <= i;j++) {
      dp[j][i] = (dp[j][i] + dp[j-1][i]) % mod;
    }
    for(int j = i;j < n;j++) {
      if(str[i] == '0') continue;
      int l = j-i;
      int k = i - l;
      if(k > 0 and pos[l][k-1] < pos[l][i]) {
        k--;
      }
      k = max(k, 0);
      if(k <= i-1) {
        dp[k][i-1] = (dp[k][i-1] + dp[i][j]) % mod;
      }
    }
  }
  
  int ans = 0;
  for(int i = 0;i < n;i++) {
    ans = (ans + dp[0][i]) % mod;
  }
  if(str[0] == '0') ans = 0;
  cout << ans << endl;

  return 0;
}