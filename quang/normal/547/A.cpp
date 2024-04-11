#include <bits/stdc++.h>

using namespace std;

int m;
int h1, a1, h2, a2;
int X1, Y1, X2, Y2;
int pos1, pos2, b1, b2, c1, c2;
int M[1000010];

void make(int &pos, int &b, int &c, int h, int a, int x, int y) {
  for (int i = 0; i < m; i++) {
    M[i] = 0;
  }
  M[h] = 1;
  pos = 0;
  int cnt = 1, cur = h;
  while (1) {
    cnt++;
    cur = (1ll * cur * x + y) % m;
    if (cur == a && !pos) {
      pos = cnt;
    }
    if (M[cur]) {
      b = cnt - M[cur];
      c = M[cur];
      return;
    }
    M[cur] = cnt;
  }
 }

long long part1(int a, int b, int c) {
  if (a < b) {
    return -1;
  }
  if ((a - b) % c) {
    return -1;
  }
  return a - 1;
}

long long part2(int a1, int b1, int a2, int b2) {
  int foo = (1ll * a2 - a1) % b1;
  foo = (1ll * foo + b1) % b1;
  foo = (b1 - foo) % b1;
  for (int i = 0; i < b1; i++) {
    int x = 1ll * b2 * i % b1;
    if (x == foo) {
      return 1ll * b2 * i + a2 - 1;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> m;
  cin >> h1 >> a1 >> X1 >> Y1;
  cin >> h2 >> a2 >> X2 >> Y2;
  make(pos1, b1, c1, h1, a1, X1, Y1);
  make(pos2, b2, c2, h2, a2, X2, Y2);
  if (pos1 < c1) {
    if (pos2 < c2) {
      cout << (pos1 != pos2 ? -1 : pos1 - 1) << endl;
    } else {
      cout << part1(pos1, pos2, b2) << endl;
    }
  } else {
    if (pos2 < c2) {
      cout << part1(pos2, pos1, b1) << endl;
    } else {
      cout << part2(pos1, b1, pos2, b2) << endl;
    }
  }
  return 0;
}