#include <bits/stdc++.h>

using namespace std;

int n;
int used[1000000];
int g[40] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
map<int, int> m;
int xxx = 29;

int go(int mask) {
  if (m.find(mask) != m.end()) {
    return m[mask];
  }
  int foo[30];
  memset(foo, 0, sizeof foo);
  for (int i = 0; i < xxx; i++) {
    if ((mask & (1 << i)) == 0) {
      continue;
    }
    int next = mask;
    for (int j = i; j < xxx; j += i + 1) {
      if (mask & (1 << j)) {
        next ^= (1 << j);
      }
    }
    int x = go(next);
    foo[x]++;
  }
  int res = 0;
  while (foo[res]) {
    res++;
  }
  return m[mask] = res;
}

void build() {
  go((1 << xxx) - 1);
  for (int i = 1; i <= xxx; i++) {
    g[i] = m[(1 << i) - 1];
  }
  for (int i = 1; i <= xxx; i++) {
    cout << g[i] << ", ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  //build();
  int res = 0;
  int cnt = n;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (used[i]) {
      continue;
    }
    int sum = 0;
    for (long long j = i; j <= n; j *= i) {
      cnt--;
      sum++;
      if (j * j <= n) {
        used[j] = 1;
      }
    }
    res ^= g[sum];
  }
  if (cnt & 1) {
    res ^= 1;
  }
  if (res) {
    cout << "Vasya";
  } else {
    cout << "Petya";
  }
  return 0;
}