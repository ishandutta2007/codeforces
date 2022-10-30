#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  const int INF = 1e9;

  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      char c;
      cin >> c;
      if (c == '0')
        A[i][j] = INF;
      else
        A[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i)
    A[i][i] = 0;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (A[i][k] + A[k][j] < A[i][j])
          A[i][j] = A[i][k] + A[k][j];
      }
  }
  int m;
  cin >> m;
  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<int> ans;
  ans.emplace_back(p[0]);
  int i = 0;
  while (i + 1 < m){
    int j = i + 2;
    while (j < m && A[p[i]][p[j]] == (j - i))
      ++j;
    ans.emplace_back(p[j - 1]);
    i = j - 1;
  }
  cout << ans.size() << "\n";
  for (int x : ans)
    cout << x + 1 << " ";
  return 0;
}