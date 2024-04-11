#include <bits/stdc++.h>

using namespace std;

int res = 0;
int n;

long long get(long long u) {
  int x = u % 4;
  long long res = 0;
  for (int i = 0; i <= x; i++) {
    res ^= (u - i);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  while (n--) {
    long long x, m;
    cin >> x >> m;
    res ^= (get(x - 1) ^ (get(x + m - 1)));
  }
  cout << (res ? "tolik" : "bolik") << endl;
  return 0;
}