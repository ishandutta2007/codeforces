#include <bits/stdc++.h>

using namespace std;

const long long MOD1 = 1000003891;
const long long MOD2 = 1000012309;

const int N = 1000100;

int n, m;
int cntTime;
string a[N];
vector < pair < int, int > > f[N];
vector < pair < int, int > > g[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n >> m;

  for(int i = 0; i <= n + 1; ++i) {
    if(i > 0 && i <= n) cin >> a[i];
    a[i] = " " + a[i];
    f[i].resize(m + 2, make_pair(0, 0));
    g[i].resize(m + 2, make_pair(0, 0));
  }


  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(i == 1 && j == 1) f[i][j] = {1, 1};
      else {
        if(a[i][j] == '#') continue;
        f[i][j].first = (f[i - 1][j].first + f[i][j - 1].first) % MOD1;
        f[i][j].second = (f[i - 1][j].second + f[i][j - 1].second) % MOD2;
      }
    }
  }



  if(f[n][m] == make_pair(0, 0)) {
    cout << 0;
    return 0;
  }

  for(int i = n; i >= 1; --i) {
    for(int j = m; j >= 1; --j) {
      if(i == n && j == m) g[i][j] = {1, 1};
      else {
        if(a[i][j] == '#') continue;
        g[i][j].first = (g[i + 1][j].first + g[i][j + 1].first) % MOD1;
        g[i][j].second = (g[i + 1][j].second + g[i][j + 1].second) % MOD2;
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(i == 1 && j == 1) continue;
      if(i == n && j == m) continue;

      int fi = (1LL * f[i][j].first * g[i][j].first) % MOD1;
      int se = (1LL * f[i][j].second * g[i][j].second) % MOD2;
      if(make_pair(fi, se) == f[n][m]) {
        cout << 1;
        exit(0);
      }
    }
  }

  cout << 2;

  return 0;
}