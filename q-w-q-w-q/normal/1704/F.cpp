#include <cstdio>
#include <iostream>

using namespace std;

int n, f[103];
char a[500005];

void prep() {
  for (int i = 2; i <= 102; i++) {
    bool u[10] = {0};
    for (int j = 1; j != i; j++)
      u[f[j - 1] ^ f[i - j - 1]] = 1;
    for (int x = 0;; x++)
      if (!u[x]) {
        f[i] = x;
        break;
      }
  }
}

void solve() {
  cin >> n >> (a + 1);
  int s = 0, ans = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    for (j = i; j < n && a[j] != a[j + 1]; j++)
      ;
    int l = j - i + 1;
    while (l > 3 * 34)
      l -= 34;
    ans ^= f[l];
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == 'R')
      s++;
    else
      s--;
  if (s > 0 || (s == 0 && ans))
    cout << "Alice\n";
  else
    cout << "Bob\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  prep();

  int t;
  cin >> t;
  while (t--)
    solve();
}

//mod mwr!!!!