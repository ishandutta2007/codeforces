#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = 0;
  for (int mx = 30; mx >= 0; mx--) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] > mx) {
        sum = 0;
        continue;
      }
      sum += A[i];
      if (sum < 0) {
        sum = 0;
      }
      ans = max(ans, sum - mx);
    }
  }

  cout << ans << "\n";
  return 0;
}