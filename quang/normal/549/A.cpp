#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[100][100];

int main() {
	cin >> n >> m;
	for (int i  = 1; i <= n; i++) {
    cin >> (a[i] + 1);
	}
  string s = "face";
  sort(s.begin(), s.end());
  int res = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      string s2 = "";
      s2 += a[i][j];
      s2 += a[i + 1][j];
      s2 += a[i + 1][j + 1];
      s2 += a[i][j + 1];
      sort(s2.begin(), s2.end());
      if (s2 == s) {
        res ++;
      }
    }
  }
  cout << res;
	return 0;
}