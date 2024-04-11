#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int minimize(int bit, vector<int> nums) {
  if (bit < 0) return 0;

  vector<int> zero, one;
  for (int num: nums) {
    if (num >> bit & 1) one.push_back(num);
    else zero.push_back(num);
  }

  if (one.size() == 0 || zero.size() == 0) return minimize(bit-1, nums);
  return min(minimize(bit-1, zero), minimize(bit-1, one)) + (1 << bit);
}

int main() {
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    v[i] = a[i];
  }

  printf("%d\n", minimize(29, v));
  return 0;
}