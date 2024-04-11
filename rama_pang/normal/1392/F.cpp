#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i;
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    a[i] = sum / n;
  }
  sum -= sum / n * n;
  for (int i = 0; i < n; i++) {
    if (sum > 0) {
      a[i] += 1;
      sum -= 1;
    }
  }
  assert(sum == 0);
  for (int i = 0; i < n; i++) {
    cout << a[i] + i << " \n"[i + 1 == n];
  }
  return 0;
}