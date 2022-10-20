#include <bits/stdc++.h>

using namespace std;

long long a, b, c, l;
long long res = 0;
long long d;

void checka() {
  long long len = d;
  while (1) {
    if (len - a > l) {
      return;
    }
    long long ex = l - (len - a);
    long long delta = len - b - c;
    if (delta < 0) {
      len++;
      continue;
    }
    if (delta == 0) {
      res++;
      len++;
      continue;
    }
    if (delta >= ex) {
      res += (ex + 1) * (ex + 2) / 2;
      len++;
      continue;
    }
    res += (delta + 1) * (delta + 2) / 2;
    len++;
  }
}

void checkb() {
  long long len = d;
  while (1) {
    if (len - b > l) {
      return;
    }
    long long ex = l - (len - b);
    long long delta = len - a - c;
    if (delta < 0) {
      len++;
      continue;
    }
    if (delta == 0) {
      res++;
      len++;
      continue;
    }
    if (delta >= ex) {
      res += (ex + 1) * (ex + 2) / 2;
      len++;
      continue;
    }
    res += (delta + 1) * (delta + 2) / 2;
    len++;
  }
}


void checkc() {
  long long len = d;
  while (1) {
    if (len - c > l) {
      return;
    }
    long long ex = l - (len - c);
    long long delta = len - b - a;
    if (delta < 0) {
      len++;
      continue;
    }
    if (delta == 0) {
      res++;
      len++;
      continue;
    }
    if (delta >= ex) {
      res += (ex + 1) * (ex + 2) / 2;
      len++;
      continue;
    }
    res += (delta + 1) * (delta + 2) / 2;
    len++;
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c >> l;
  d = max(a, max(b, c));
  checka();
  checkb();
  checkc();
  res = (l + 3) * (l + 2) * (l + 1) / 6 - res;
  cout << res << endl;
  return 0;
}