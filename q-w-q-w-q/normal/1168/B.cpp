#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 300005;
int n, l[N];
long long ans;
char a[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> (a + 1), n = strlen(a + 1);

  for (int i = 2; i < n; i++) {
    int len = min(min(i - 1, n - i), 100);
    for (int j = 1; j <= len; j++)
      if (a[i] == a[i - j] && a[i] == a[i + j]) {
        l[i + j] = max(l[i + j], i - j);
        break;
      }
  }

  for (int i = 1, x = 0; i <= n; i++)
    x = max(x, l[i]), ans += x;
  cout << ans;
}