#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define pii pair <int, int>

using namespace std;

int a[10];

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int uk = 0, sol = 0;
    REP(i, 7) {
      cin >> a[i];
      uk += a[i];
    }
    sol += (n / uk);
    n %= uk;

    if (n == 0) {
      n += uk;
      sol--;
    }

    int mi = 100;
    REP(i, 7) {
      int ind = i, d = 0, curr = 0;
      while (curr < n) {
        curr += a[ind];
        ind = (ind + 1) % 7;
        d++;
      }
      mi = min(d, mi);
    }
    cout << sol*7 + mi << "\n";
  }

  return 0;
}