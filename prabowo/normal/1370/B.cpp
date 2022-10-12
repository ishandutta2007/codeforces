#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
const int MOD = 998244353;



int solve() {
  int n;
  scanf("%d", &n);
  vector<int> nums[2];

  for (int i = 0; i < n*2; ++i) {
    int a;
    scanf("%d", &a);
    nums[a & 1].push_back(i);
  }

  for (int i = 0; i < n-1; ++i) {
    if (nums[0].size() >= 2) {
      printf("%d %d\n", nums[0].back() + 1, nums[0][nums[0].size() - 2] + 1);
      nums[0].pop_back();nums[0].pop_back();
    } else {
      printf("%d %d\n", nums[1].back() + 1, nums[1][nums[1].size() - 2] + 1);
      nums[1].pop_back();nums[1].pop_back();
    }
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}