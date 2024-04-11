#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int h;
long long n;

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> h >> n;
  n--;
  long long res = 1;
  bool du = 0;
  for (int i = h - 1; i >= 0; i--) {
    res++;
    bool mask = (n >> i) & 1;
    if (mask ^ du)
      res += (1ll << (i + 1)) - 1;
    du = mask ^ 1;
  }
  cout << res - 1;
  return 0;
}