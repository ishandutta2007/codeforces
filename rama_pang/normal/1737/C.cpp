#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N;
  cin >> N;
  int r1, c1, r2, c2, r3, c3;
  cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
  int r = r1 + r2 + r3 - min({r1, r2, r3}) - max({r1, r2, r3});
  int c = c1 + c2 + c3 - min({c1, c2, c3}) - max({c1, c2, c3});
  int x, y;
  cin >> x >> y;
  if (r == 1 && c == 1) {
    if (x == 1 || y == 1) cout << "YES\n";
    else cout << "NO\n";
  } else if (r == 1 && c == N) {
    if (x == 1 || y == N) cout << "YES\n";
    else cout << "NO\n";
  } else if (r == N && c == 1) {
    if (x == N || y == 1) cout << "YES\n";
    else cout << "NO\n";
  } else if (r == N && c == N) {
    if (x == N || y == N) cout << "YES\n";
    else cout << "NO\n";
  } else {
    int diffx = abs(x - r);
    int diffy = abs(y - c);
    if (diffx % 2 == 1 && diffy % 2 == 1) cout << "NO\n";
    else cout << "YES\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T =1 ;
  cin >> T;
  while (T--) Main();
}