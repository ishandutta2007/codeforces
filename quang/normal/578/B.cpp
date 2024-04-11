#include <bits/stdc++.h>

using namespace std;

const int N = 200100;
typedef unsigned long long ull;

ull n, x, k;
ull a[N], p, res = 0;
ull pre[N], suf[N];

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  //freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] | a[i];
  }
  for (int i = n; i; i--) {
    suf[i] = suf[i + 1] | a[i];
  }
  p = 1;
  for (int i = 1; i <= k; i++) {
    p *= x;
  }
  for (int i =1 ; i <= n; i++) {
    ull foo = pre[i - 1] | suf[i + 1];
    foo |= (a[i] * p);
    res = max(res, foo);
  }
  cout << res << endl;
  return 0;
}