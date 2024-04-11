#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  long long x;
  cin >> n >> x;
  
  vector<long long> a(n);
  vector<long long> p(n);

  long long sum = 0;
  long long points = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = a[i] * (a[i] + 1) / 2;

    sum += a[i];
    points += p[i];
  }

  long long ans = 0;
  long long ans2 = 0;

  if (x >= sum) {
    ans += x / sum * points;
    x %= sum;
  }

  for (int i = 0; i < n; i++) {
    a.emplace_back(a[i]);
    p.emplace_back(p[i]);
  }

  sum = 0;
  points = 0;
  for (int i = 0, j = 0; i < 2 * n; i++) {
    while (j < 2 * n && sum < x) {
      sum += a[j];
      points += p[j];
      j++;
    }

    if (sum >= x) {
      long long cur = points;
      long long cant = sum - x;
      cur -= cant * (cant + 1) / 2;
      ans2 = max(ans2, cur);
    }
    
    sum -= a[i];
    points -= p[i];
  }

  cout << ans + ans2 << "\n";
  return 0;
}