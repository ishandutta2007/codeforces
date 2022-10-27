#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 10005;
int n, p[N];

int qy(int i) {
  cout << "? " << i << endl;
  int x;
  cin >> x;
  return x;
}

void solve() {
  static int st[N];
  cin >> n, qy(1);

  for (int i = 1; i < n; i++)
    if (!p[i]) {
      int top = 1;
      st[1] = qy(i);
      while (1) {
        st[++top] = qy(i);
        if (st[top] == st[1])
          break;
      }
      for (int i = 1; i < top; i++)
        p[st[i]] = st[i + 1];
    }
  if (!p[n])
    p[n] = n;

  cout << "!";
  for (int i = 1; i <= n; i++)
    cout << ' ' << p[i];
  cout << endl;

  memset(p, 0, sizeof p);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}