#include <bits/stdc++.h>

using namespace std;

int n;
int a[30];
int sum, numodd, posodd;

void go1() {
  int cnt = a[posodd];
  for (int i = 0; i < n; i++) {
    if (i != posodd) {
      cnt = __gcd(cnt, a[i] / 2);
    }
  }
  string x = "";
  for (int i = 0; i < n; i++) {
    if (i != posodd) {
      for (int j = 0; j < a[i] / 2 / cnt; j++) {
        x += 'a' + i;
      }
    } else {
      for (int j = 0; j < (a[i] - cnt) / 2 / cnt; j++) {
        x += 'a' + i;
      }
    }
  }
  string y = x;
  reverse(y.begin(), y.end());
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    cout << x << (char)(posodd + 'a') << y;
  }
}

void go0() {
  int cnt = a[0];
  for (int i = 1; i < n; i++) {
    cnt = __gcd(a[i], cnt);
  }
  string x = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i] / cnt; j++) {
      x += 'a' + i;
    }
  }
  string y = x;
  reverse(y.begin(), y.end());
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    if (i & 1) {
      cout << x;
    } else {
      cout << y;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum += a[i];
    if (a[i] & 1) {
      numodd++;
      posodd = i;
    }
  }
  if (n == 1) {
    cout << a[0] << endl;
    for (int i = 1; i <= a[0]; i++) {
      putchar('a');
    }
    return 0;
  }

  if (numodd > 1) {
    cout << 0 << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i]; j++) {
        putchar('a' + i);
      }
    }
    return 0;
  }
  if (numodd) {
    go1();
  } else {
    go0();
  }
  return 0;
}