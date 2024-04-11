#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
  int m, n, k, t;
  cin >> m >> n >> k >> t;
  t -= n + 1;
  vector<int> A(m);
  for (int i = 0; i < m; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  vector<pair<int, int>> B(2 * k);
  for (int i = 0; i < k; ++i){
    int l, r, d;
    cin >> l >> r >> d;
    B.emplace_back(l - 1, d);
    B.emplace_back(r, -d);
  }
  sort(B.begin(), B.end());
  int left = 0, right = m + 1;
  while (right - left > 1){
    int mid = (left + right) / 2;
    int mn = A[m - mid];
    int bal = 0;
    int len = 0;
    int prevx = 0;
    //cout << '\n';
    for (int i = 0; i < B.size(); ++i){
      if (abs(B[i].second) > mn){
        //cout << B[i].first << ' ' << B[i].second << ' ' << bal << '\n';
        if (bal)
          len += B[i].first - prevx;
        if (B[i].second > 0)
          ++bal;
        else
          --bal;
        prevx = B[i].first;
      }
    }
    //cout << len << '\n';
    if (2 * len <= t)
      left = mid;
    else
      right = mid;
  }
  cout << left;
  return 0;
}