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
  vector<int> A(n);
  vector<int> B(n);
  vector<int> C(n);
  for (int i = 0; i < n; ++i){
    cin >> A[i];
    C[A[i] - 1] += i;
  }
  for (int i = 0; i < n; ++i){
    cin >> B[i];
    C[B[i] - 1] -= i;
  }
  for (int i = 0; i < n; ++i){
    C[i] = (C[i] + n) % n;
  }
  map<int, int> ans;
  for (int i = 0; i < n; ++i){
    if (!ans.count(C[i]))
      ans[C[i]] = 0;
    ++ans[C[i]];
  }
  int res = 0;
  for (auto t: ans)
    res = max(res, t.second);
  cout << res << '\n';
  return 0;
}