#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<long long> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  long long res = 0;
  for (int i = 0; i < n; ++i)
    res = max(res, A[i]);
  for (int i = 0; i < n; ++i){
    for (int j = i + 1; j < n; ++j)
      res = max(res, A[i] | A[j]);
  }
  for (int i = 0; i < n; ++i){
    for (int j = i + 1; j < n; ++j){
      for (int k = j + 1; k < n; ++k)
        res = max(res, A[i] | A[j] | A[k]);
    }
  }
  cout << res << '\n';
  return 0;
}