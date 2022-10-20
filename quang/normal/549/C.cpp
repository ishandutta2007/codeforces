#include <bits/stdc++.h>

using namespace std;

#define Awin "Stannis"
#define Bwin "Daenerys"

int n, k;
int odd, even;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x & 1) {
      odd++;
    } else {
      even++;
    }
  }
  if (k == n) {
    if (odd & 1) {
      puts(Awin);
    } else {
      puts(Bwin);
    }
    return 0;
  }
  int moves = n - k;
  int amove = (moves + 1) / 2;
  int bmove = moves / 2;
  if (moves & 1) {
    if (k & 1) {
      if (bmove >= odd) {
        puts(Bwin);
      } else {
        puts(Awin);
      }
    } else {
      if (bmove >= odd || bmove >= even) {
        puts(Bwin);
      } else {
        puts(Awin);
      }
    }
  } else {
    if (k & 1) {
      if (amove >= even) {
        puts(Awin);
      } else {
        puts(Bwin);
      }
    } else {
      puts(Bwin);
    }
  }
  return 0;
}