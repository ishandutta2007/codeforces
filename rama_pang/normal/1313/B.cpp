#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;

    int ansMin = max(1, min(n, x + y + 1 - n)); // (1, x+y), (2, x+y-1), ..., (x+y, 1). But if max position is n, then can only start from ((x+y+1) - n, n)
    int ansMax = min(n, x + y - 1); // there are (x + y - 1) ways to form (x + y)
    cout << ansMin << " " << ansMax << "\n";
  }
}