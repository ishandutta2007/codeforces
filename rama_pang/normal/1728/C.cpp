#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;  
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  map<int, int> cnt;
  for (auto i : a) {
    cnt[i]++;
  }
  for (auto i : b) {
    cnt[i]--;
  }
  int ans = 0;
  while (cnt.size() > 0) {
    auto it = prev(end(cnt));
    if (it->second == 0) {
      cnt.erase(it);
      continue;
    }
    int f = to_string(it->first).size();
    int g = it->second;
    cnt.erase(it);
    cnt[f] += g;
    ans += abs(g);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}