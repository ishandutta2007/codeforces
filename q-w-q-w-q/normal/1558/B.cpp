#include <cstdio>
#include <iostream>
using namespace std;
const int N = 4000005;
int n, mod, f[N];
int h[N], ne[N], st[N], top;
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x < y ? x + mod - y : x - y; }
int main() {
  cin >> n >> mod;
  f[1] = 1;
  for (int i = 2, s = 1, ss = 0; i <= n; i++) {
    top = 0;
    ne[i] = h[i], h[i] = i;
    for (int k = h[i]; k; k = ne[k]) {
      ss = sub(ss, f[i / k - 1]), ss = add(ss, f[i / k]);
      st[++top] = k;
    }
    f[i] = add(s, ss), s = add(s, f[i]);
    while (top) {
      int x = st[top--];
      if (i + x <= n) ne[x] = h[i + x], h[i + x] = x;
    }
  }
  cout << f[n];
}