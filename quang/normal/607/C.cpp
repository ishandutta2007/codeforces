#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
char a[N], b[N];
int t[N];

int main() {
  scanf("%d", &n);
  n--;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) {
    if (b[i] == 'W') b[i] = 'E'; else
    if (b[i] == 'E') b[i] = 'W'; else
    if (b[i] == 'N') b[i] = 'S'; else
    b[i] = 'N';
  }
  reverse(b + 1, b + n + 1);
  int cur = 0;
  t[1] = 0;
  for (int i = 2; i <= n; i++) {
    while (cur && b[i] != b[cur + 1]) {
      cur = t[cur];
    }
    cur += (b[i] == b[cur + 1]);
    t[i] = cur;
  }
  cur = 0;
  for (int i = 1; i <= n; i++) {
    while (cur && a[i] != b[cur + 1]) {
      cur = t[cur];
    }
    cur += (a[i] == b[cur + 1]);
  }
  cout << (cur ? "NO" : "YES") << endl;
  return 0;
}