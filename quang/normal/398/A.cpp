#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a, b;
long long res = -(1ll << 60);
pair<int, int> ans;
long long suma[N], sumb[N];
char out[N];

int main() {
  cin >> a >> b;
  if (!a) {
    cout << -1ll * b * b << endl;
    for (int i = 1; i <= b; i++) {
      cout << 'x';
    }
    return 0;
  }
  if (!b) {
    cout << 1ll * a * a << endl;
    for (int i = 1; i <= a; i++) {
      cout << 'o';
    }
    return 0;
  }
  for (int i = 1; i <= a; i++) {
    suma[i] = 1ll * (a - i + 1) * (a - i + 1) + (i - 1);
  }
  for (int i = 1; i <= b; i++) {
    int foo = b / i;
    int bar = b % i;
    sumb[i] = 1ll * bar * (foo + 1) * (foo + 1) + 1ll * foo * foo * (i - bar);
  }
  suma[0] = a ? -(1ll << 60) : 0;
  sumb[0] = b ? (1ll << 60) : 0;
  for (int i = 0; i <= a; i++) {
    if (i && i - 1 <= b) {
      if (suma[i] - sumb[i - 1] > res) {
        res = suma[i] - sumb[i - 1];
        ans = make_pair(i, i - 1);
      }
    }
    if (i < b) {
      if (suma[i] - sumb[i + 1] > res) {
        res = suma[i] - sumb[i + 1];
        ans = make_pair(i, i + 1);
      }
    }
    if (i <= b) {
      if (suma[i] - sumb[i] > res) {
        res = suma[i] - sumb[i];
        ans = make_pair(i, i);
      }
    }
  }
  printf("%I64d\n", res);
  int cur = 0;
  int f1 = b / ans.second, f2 = b % ans.second;
  for (int i = 1; i <= min(ans.first, ans.second); i++) {
    for (int j = 1; j <= f1 + (i <= f2); j++) {
      out[cur++] = 'x';
    }
    if (i == 1) {
      for (int j = 1; j <= a - ans.first + 1; j++) {
        out[cur++] = 'o';
      }
    } else {
      out[cur++] = 'o';
    }
  }
  if (ans.first < ans.second) {
    for (int i = 1; i <= f1; i++) {
      out[cur++] = 'x';
    }
  }
  if (ans.first > ans.second) {
    reverse(out, out + cur);
    out[cur++] = 'o';
  }
  printf("%s", out);
  return 0;
}