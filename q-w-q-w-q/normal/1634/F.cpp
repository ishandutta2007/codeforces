#include <cstdio>
#include <iostream>

using namespace std;

const int N = 300005;
int n, q, mod, tot;
int a[N], f[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
int sub(int x, int y) { return x < y ? x + mod - y : x - y; }

void modify(int i, int x) {
  if (i < 1 || i > n)
    return;
  if (!a[i])
    tot--;
  a[i] = add(a[i], x);
  if (!a[i])
    tot++;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q >> mod;
  f[0] = f[1] = 1;
  for (int i = 2; i <= n; i++)
    f[i] = add(f[i - 1], f[i - 2]);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = sub(a[i], x);
  }
  for (int i = n; i > 1; i--)
    a[i] = sub(a[i], add(a[i - 1], a[i - 2]));
  for (int i = 1; i <= n; i++)
    if (!a[i])
      tot++;

  while (q--) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    if (l == r) {
      if (op == 'A')
        modify(l, 1), modify(l + 1, mod - 1), modify(l + 2, mod - 1);
      else
        modify(l, mod - 1), modify(l + 1, 1), modify(l + 2, 1);
    } else {
      if (op == 'A') {
        modify(l, 1);
        modify(r + 1, mod - f[r - l + 1]);
        modify(r + 2, mod - f[r - l]);
      } else {
        modify(l, mod - 1);
        modify(r + 1, f[r - l + 1]);
        modify(r + 2, f[r - l]);
      }
    }
    puts(tot == n ? "yes" : "no");
  }
}