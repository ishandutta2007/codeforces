#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> A[i][j];
    }
  }
  for (int i = n - 1; i >= 0; --i){
    for (int j = m - 1; j >= 0; --j){
      if (A[i][j] == 0){
        A[i][j] = min(A[i + 1][j], A[i][j + 1]) - 1;
      }
    }
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      if ((i > 0 && A[i][j] <= A[i - 1][j]) || (j > 0 && A[i][j] <= A[i][j - 1])){
        cout << -1;
        return 0;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      ans += A[i][j];
    }
  }
  cout << ans;
  return 0;
}