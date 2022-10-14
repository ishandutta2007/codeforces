#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  int o = 0, e = 0;
  for (int i = 0; i < 2 * n; i++) {
    int x;
    cin >> x;
    if (x & 1) o++;
    else e++;
  }
  if (o == e) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}