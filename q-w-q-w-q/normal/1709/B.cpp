#include <cstdio>
#include <iostream>

using namespace std;

int n, m, a[100005];
long long s1[100005], s2[100005];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 2; i <= n; i++) {
    s1[i] = s1[i - 1];
    if (a[i - 1] > a[i])
      s1[i] += a[i - 1] - a[i];
  }
  for (int i = n - 1; i; i--) {
    s2[i] = s2[i + 1];
    if (a[i] < a[i + 1])
      s2[i] += a[i + 1] - a[i];
  }
  while (m--) {
    int s, t;
    cin >> s >> t;
    if (s < t)
      cout << s1[t] - s1[s] << '\n';
    else
      cout << s2[t] - s2[s] << '\n';
  }
}