#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = 0;
  long long total_inv = 0;

  vector<vector<int>> blocks;
  vector<vector<int>> newblocks;
  blocks.emplace_back(A);
  for (int bit = 30; bit >= 0; bit--) {
    long long inv_if_0 = 0;
    long long inv_if_1 = 0;
    newblocks.clear();
    for (const auto &b : blocks) {
      static vector<int> v1, v2; 
      v1.clear(); v2.clear();
      int sum0 = 0, sum1 = 0;
      for (int i = int(b.size()) - 1; i >= 0; i--) {
        if ((b[i] >> bit) & 1) {
          inv_if_0 += sum0;
          sum1 += 1;
          v1.emplace_back(b[i]);
        } else {
          inv_if_1 += sum1;
          sum0 += 1;
          v2.emplace_back(b[i]);
        }
      }
      reverse(begin(v1), end(v1));
      reverse(begin(v2), end(v2));
      if (!v1.empty()) newblocks.emplace_back(v1);
      if (!v2.empty()) newblocks.emplace_back(v2);
    }
    swap(blocks, newblocks);

    if (inv_if_0 > inv_if_1) {
      ans |= 1 << bit;
      total_inv += inv_if_1;
    } else {
      total_inv += inv_if_0;
    }
  }

  cout << total_inv << ' ' << ans << '\n';
  return 0;
}