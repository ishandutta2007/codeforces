#include <bits/stdc++.h>

using namespace std;

int tab[20][20];

string s = "a1 c1 d1 e1 f1 g1 h1 b1 b2 a2 ";

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  if (n <= 53) {
    int x = 1, y = 1;
    cout << (char) (x + 'a' - 1) << y << " ";
    for (int i = 0; i < n-2; i++) {
      if (y%2) {
        if (x == 8) {
          y++;
        } else {
          x++;
        }
      } else {
        if (x == 1) {
          y++;
        } else {
          x--;
        }
      }
      cout << (char) (x + 'a' - 1) << y << " ";
    }
    if (y == 8) {
      x = 7;
      cout << (char) (x + 'a' - 1) << y << " ";
      x = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
    } else if (x == 8) {
      y = 7;
      cout << (char) (x + 'a' - 1) << y << " ";
      y = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
    } else {
      y = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
      x = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
    }
  } else {
    n -= 10;
    cout << s;
    int x = 3, y = 2;
    cout << (char) (x + 'a' - 1) << y << " ";
    for (int i = 0; i < n-2; i++) {
      if (y%2 == 0) {
        if (x == 8) {
          y++;
        } else {
          x++;
        }
      } else {
        if (x == 1) {
          y++;
        } else {
          x--;
        }
      }
      cout << (char) (x + 'a' - 1) << y << " ";
    }
    if (y == 8) {
      x = 7;
      cout << (char) (x + 'a' - 1) << y << " ";
      x = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
    } else if (x == 8) {
      y = 7;
      cout << (char) (x + 'a' - 1) << y << " ";
      y = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
    } else {
      y = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
      x = 8;
      cout << (char) (x + 'a' - 1) << y << " ";
    }
  }
  return 0;
}