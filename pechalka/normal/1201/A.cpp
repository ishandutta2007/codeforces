#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <map>

using namespace std;

const int MAXN = 1000;

int cnt[MAXN][5];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      char c;
      cin >> c;
      ++cnt[j][c - 'A'];
    }
  }
  vector<int> A(m);
  for (int  i = 0; i < m; ++i)
    cin >> A[i];
  int ans = 0;
  for (int i = 0; i < m; ++i){
    int mx = 0;
    for (int j = 0; j < 5; ++j)
      mx = max(mx, cnt[i][j]);
    ans += mx * A[i];
  }
  cout << ans;
  return 0;
}