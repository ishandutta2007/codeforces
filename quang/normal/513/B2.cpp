#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, a[100], d = 1;
long long m;

void Go(int l, int r) {
  if (l > r) return;
  if (m >= (1ll << (r - l - 1))) {
    m -= (1ll << (r - l - 1));
    a[r] = d++;
    Go(l, r - 1);
  } else {
    a[l] = d++;
    Go(l + 1, r);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  m--;
  Go(1, n);
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}