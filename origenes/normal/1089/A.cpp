#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int N = 10;

int a[N], b[N], m;

bool check30(int x, int y) {
  if (x < 75) return false;
  x -= 75;
  a[1] = a[2] = a[3] = 25;

  if (x) {
    if (y < x + 23) return false;
    if (y > x + 23 * 3) return false;
    a[1] += x;
    b[1] = x + 23;
    y -= x + 23;
    for (int i = 2; i <= 3; i++) {
      b[i] = min(y, 23);
      y -= min(y, 23);
    }
    return true;
  } else {
    if (y > 69) return false;
    for (int i = 1; i <= 3; i++) {
      b[i] = min(y, 23);
      y -= min(y, 23);
    }
    return true;
  }

}

bool check31(int x, int y) {
  if (x < 75 || y < 25) return false;
  a[2] = a[3] = a[4] = 25;
  b[1] = 25;
  x -= 75;
  y -= 25;

//  if (x <= 23 && y <= 69) {
//    a[1] = x;
//    for (int i = 2; i <= 4; i++) {
//      b[i] = min(y, 23);
//      y -= min(y, 23);
//    }
//    return true;
//  } else if (x <= 23 && y > 69) {
//    if (y - 69 > x) return false;
//    b[2] = b[3] = b[4] = 23;
//    y -= 69;
//    b[2] += y;
//    a[2] += y;
//    a[1] = x - y;
//
//    return true;
//  } else if (x > 23 && y <= 69) {
//    if (x - 23 > y) return false;
//    a[1] = 23;
//    x -= 23;
//    b[1] += x;
//    a[1] += x;
//    y -= x;
//    for (int i = 2; i <= 4; i++) {
//      b[i] = min(y, 23);
//      y -= min(y, 23);
//    }
//    return true;
//  } else {
//    if (x - 23 >= y - 69) {
//      a[1] = x;
//      b[1] += x - 23;
//      y -= x - 23;
//      if (y < 0) return false;
//      for (int i = 2; i <= 4; i++) {
//        b[i] = min(y, 23);
//        y -= min(y, 23);
//      }
//      return true;
//    } else {
//      b[2] = b[3] = b[4] = 23;
//      y -= 69;
//      b[2] += y;
//      a[2] += y;
//      x -= y;
//      if (x < 0) return false;
//      a[1] = x;
//      return true;
//    }
//  }

  if (x - 23 >= y - 69) {
    a[1] = min(x, 23);
    x -= min(x, 23);
    a[1] += x;
    b[1] += x;
    y -= x;
    if (y < 0) return false;

    for (int i = 2; i <= 4; i++) {
      b[i] = min(y, 23);
      y -= min(y, 23);
    }
    return true;
  } else {
    for (int i = 2; i <= 4; i++) {
      b[i] = min(y, 23);
      y -= min(y, 23);
    }

    a[2] += y;
    b[2] += y;
    x -= y;
    if (x < 0) return false;
    a[1] = x;
    return true;
  }
}

bool check32(int x, int y) {
  if (x < 65 || y < 50) return false;
  a[3] = a[4] = 25;
  a[5] = 15;
  b[1] = b[2] = 25;
  x -= 65;
  y -= 50;

  if (x - 46 >= y - 59) {
    for (int i = 1; i <= 2; i++) {
      a[i] = min(x, 23);
      x -= min(x, 23);
    }
    a[1] += x;
    b[1] += x;
    y -= x;

    if (y < 0) return false;
    for (int i = 3; i <= 4; i++) {
      b[i] = min(y, 23);
      y -= min(y, 23);
    }
    b[5] = y;
    return true;
  } else {
    for (int i = 3; i <= 4; i++) {
      b[i] = min(y, 23);
      y -= min(y, 23);
    }
    b[5] = min(y, 13);
    y -= min(y, 13);

    b[3] += y;
    a[3] += y;
    x -= y;
    if (x < 0) return false;
    for (int i = 1; i <= 2; i++) {
      a[i] = min(x, 23);
      x -= min(x, 23);
    }
    return true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;

    if (check30(x, y)) {
      cout << "3:0\n";
      for (int i = 1; i <= 3; i++) cout << a[i] << ":" << b[i] << ' ';
    } else if (check31(x, y)) {
      cout << "3:1\n";
      for (int i = 1; i <= 4; i++) cout << a[i] << ":" << b[i] << ' ';
    } else if (check32(x, y)) {
      cout << "3:2\n";
      for (int i = 1; i <= 5; i++) cout << a[i] << ":" << b[i] << ' ';
    } else if (check32(y, x)) {
      cout << "2:3\n";
      for (int i = 1; i <= 5; i++) cout << b[i] << ":" << a[i] << ' ';
    } else if (check31(y, x)) {
      cout << "1:3\n";
      for (int i = 1; i <= 4; i++) cout << b[i] << ":" << a[i] << ' ';
    } else if (check30(y, x)) {
      cout << "0:3\n";
      for (int i = 1; i <= 3; i++) cout << b[i] << ":" << a[i] << ' ';
    } else cout << "Impossible";
    cout << '\n';
  }
  return 0;
}

/*
 6
 75 0
 90 90
 20 0
 0 75
 78 50
 80 100
 */