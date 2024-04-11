#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n;
int a[N][N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    string s; cin >> s;
    for(int j = 1; j <= n; ++j) {
      a[i][j] = s[j - 1] - '0';
      if(a[i][j] == 0) a[i][j] = 1e9;
    }
    a[i][i] = 0;
  }

  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  int m; 
  cin >> m;

  vector < int > path(m), dp(m, 1e9), trace(m, -1);

  dp[0] = 0;

  for(int &x : path) cin >> x;

  for(int i = 1; i < m; ++i) {
    for(int j = i - 1; j >= max(0, j - n); --j) {
      if(a[path[j]][path[i]] != a[path[j + 1]][path[i]] + 1) break;
      if(dp[j] + 1 < dp[i]) {
        dp[i] = dp[j] + 1;
        trace[i] = j;
      }  
    }
  }

  vector < int > res;

  int x = m - 1;
  while(x >= 0) {
    res.push_back(x);
    x = trace[x];
  }

  cout << res.size() << endl;
  for(int i = res.size() - 1; i >= 0; --i) {
    cout << path[res[i]] << " ";
  }

  return 0;
}