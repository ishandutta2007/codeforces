#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 25;
int n;
long long a[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      while (a[i] % 2 == 0)
        a[i] /= 2, cnt++;
    }
    sort(a + 1, a + n + 1);
    while (cnt--)
      a[n] *= 2;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      ans += a[i];
    cout << ans << '\n';
  }
}