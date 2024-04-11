#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;
  map<string, int> ans;
  for (char c = '1'; c <= '9'; c++) {
    string s;
    for (int rep = 0; rep < 4; rep++) {
      s.push_back(c);
      cnt += rep + 1;
      ans[s] = cnt;
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << ans[to_string(n)] << "\n";
  }
  return 0; 
}