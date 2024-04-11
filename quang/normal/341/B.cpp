#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int res = 0;
int b[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    b[i] = 1000000000;
    int x;
    cin >> x;
    int pos = lower_bound(b, b + i + 1, x) - b;
    res = max(res, pos);
    b[pos] = x;
  }
  cout << res;
  return 0;
}