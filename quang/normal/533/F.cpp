#include <bits/stdc++.h>

using namespace std;

const int base = 37;
const int N = 200010;

string s, t;
int n, m;
bool dd[30];
vector <int> res;
long long h[30], p[N], f[30];

void turn (int u) {
  for (int i = 0; i < 26; i++) {
    f[i] *= base;
  }
  f[s[u] - 'a']++;
  f[s[u - m] - 'a'] -= p[m];
}

bool check() {
  memset(dd, 0, sizeof dd);
  for (int i = 0; i < 26; i++) {
    if (dd[i]) {
      continue;
    }
    bool flag = 0;
    for (int j = i; j < 26; j++) {
      if (!dd[j] && f[i] == h[j] && f[j] == h[i]) {
        dd[j] = 1;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  cin >> s >> t;
  p[0] = 1;
  for (int i = 1; i <= m + 1; i++) {
    p[i] = p[i - 1] * base;
  }
  for (int i = 0; i < m; i++) {
    h[t[i] - 'a'] += p[m - i - 1];
  }
  for (int i = 0; i < m; i++) {
    f[s[i] - 'a'] += p[m - i - 1];
  }
  if (check()) {
    res.push_back(1);
  }
  for (int i = m; i < n; i++) {
    turn(i);
    if (check()) {
      res.push_back(i - m + 2);
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}