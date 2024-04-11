#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;

int main() {
  scanf("%d", &n);
  int low = -INF, high = INF;
  int curAdd = 0;
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (v == 1) {
      low = max(low, 1900 - curAdd);
    } else {
      high = min(high, 1899 - curAdd);
    }
    curAdd += u;
  }
  if (low > high) {
    puts("Impossible");
    return 0;
  }
  if (high >= INF) {
    puts("Infinity");
    return 0;
  }
  cout << high + curAdd << endl;
  return 0;
}