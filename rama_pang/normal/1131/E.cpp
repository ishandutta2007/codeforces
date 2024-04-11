#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int n;
vector<string> s;

int memo[100005][256];
int IsThere(int id, char c) {
  if (id < 0) return 0;
  if (memo[id][c] != -1) return memo[id][c];
  for (auto j : s[id]) {
    if (j == c) {
      return memo[id][c] = 1;
    }
  }
  return memo[id][c] = IsThere(id - 1, c);
}

int FindLongest(int id, char c) {
  if (id < 0) return 0; 
  string cur = s[id];
  int ans = IsThere(id, c);
  for (int i = 0; i < (int) cur.size(); i++) {
    if (cur[i] != c) {
      continue;
    }
    int j = i;
    while (j + 1 < (int) cur.size() && cur[j + 1] == c) {
      j++;
    }
    ans = max(ans, j - i + 1);
    if (i == 0 && j + 1 == (int) cur.size()) {
      int len = FindLongest(id - 1, c);
      ans = max(ans, len + (len + 1) * int(cur.size()));
    } else if (i == 0) {
      ans = max(ans, (j - i + 1) + IsThere(id - 1, c));
    } else if (j + 1 == (int) cur.size()) {
      ans = max(ans, (j - i + 1) + IsThere(id - 1, c));
    }
    i = j;
  }
  if (cur.front() == c && cur.front() == cur.back() && IsThere(id - 1, c)) {
    int len = 0;
    for (auto i : cur) {
      if (i != c) {
        break;
      }
      len++;
    }
    reverse(begin(cur), end(cur));
    for (auto i : cur) {
      if (i != c) {
        break;
      }
      len++;
    }
    ans = max(ans, len + 1);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(memo, -1, sizeof(memo));

  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    ans = max(ans, FindLongest(n - 1, c));
  }
  cout << ans << "\n";
  return 0;
}