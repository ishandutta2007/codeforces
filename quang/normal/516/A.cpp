#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n;
string s;
int sl[20];
vector <int> d[20];

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n;
  cin >> s;
  d[4].push_back(2);
  d[4].push_back(2);
  d[6].push_back(2);
  d[8].push_back(2);
  d[8].push_back(2);
  d[8].push_back(2);
  d[6].push_back(3);
  d[9].push_back(3);
  d[9].push_back(3);
  for (int i = 0; i < n; i++) {
    int u = s[i] - '0';
    for (int j = 2; j <= u; j++) {
      sl[j]++;
    }
  }
  for (int i = 9; i >= 4; i--) {
    if (d[i].empty()) {
      continue;
    }
    for (int j = 0; j < d[i].size(); j++) {
      sl[d[i][j]] += sl[i] - sl[i + 1];
    }
    sl[i] = sl[i + 1];
  }
  for (int i = 9; i >= 2; i--) {
    for (int j = 1; j <= sl[i] - sl[i + 1]; j++) {
      cout << i;
    }
  }
  return 0;
}