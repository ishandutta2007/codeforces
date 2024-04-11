#include<bits/stdc++.h>

using namespace std;

int n, m, k;

vector<pair<int, string>> ans;

void mov(int d, string cur) {
  if(d < 0) return;
  if(k == 0) return;

  int x = min(d, k / (int)cur.size());
  if(x > 0) ans.emplace_back(x, cur);
  k -= x * cur.size();
  d -= x;
  if(d > 0 && k > 0) {
    for(int i = 0; i < k; ++i) {
      ans.emplace_back(1, string(1, cur[i]));
    }
    k = 0;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string L = "L";
  string R = "R";
  string U = "U";
  string D = "D";

  cin >> n >> m >> k;

  if(k > (4 * m * n - 2 * n - 2 * m)) {
    cout << "NO";
    return 0;
  }

  cout << "YES" << endl;

  mov(m - 1, R);
  for(int i = 1; i < n; ++i) {
    swap(L, R);
    mov(1, D);
    mov(m - 1, R);
  }

  for(int i = 1; i < n; ++i) {
    swap(L, R);
    mov(m - 1, U + D + R);
    mov(1, U);
  }

  mov(m - 1, L);

  cout << ans.size() << endl;
  for(auto &p : ans) cout << p.first << " " << p.second << endl;

  return 0;
}