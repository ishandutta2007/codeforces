#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

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
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  vector<int> maxUp(n);
  for (int i = n - 1; i >= 0; --i){
    maxUp[i] = 1;
    if (i + 1 < n && A[i + 1] > A[i])
      maxUp[i] += maxUp[i + 1];
  }
  vector<int> maxUpTo(n);
  for (int i = 0; i < n; ++i){
    maxUpTo[i] = 1;
    if (i - 1 >= 0 && A[i] > A[i - 1])
      maxUpTo[i] += maxUpTo[i - 1];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, maxUp[i]);
  for (int i = 1; i + 1 < n; ++i){
    if (A[i + 1] > A[i - 1])
      ans = max(ans, maxUpTo[i - 1] + maxUp[i + 1]);
  }
  cout << ans << '\n';
  return 0;
}