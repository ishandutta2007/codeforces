#include <bits/stdc++.h>

using namespace std;

int a(int u, int v) {
  return u ^ v;
}

int b(int u, int v) {
  return u | v;
}

int c(int u, int v) {
  return u & v;
}

int main() {
  int v[4];
  for (int i = 0; i < 4; i++) {
    cin >> v[i];
  }
  int vv[4];
  vv[0] = a(v[0], v[1]);
  vv[1] = b(v[2], v[3]);
  vv[2] = c(v[1], v[2]);
  vv[3] = a(v[0], v[3]);
  int vvv[2];
  vvv[0] = c(vv[0], vv[1]);
  vvv[1] = b(vv[2], vv[3]);
  cout << a(vvv[0], vvv[1]);
  return 0;
}