#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// gp_hash_table<int, int> freq;
map<int, int> freq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  if (n <= 2) {
    if (m == 0) {
      if (n == 1) {
        cout << 1 << "\n";
      } else if (n == 2) {
        cout << 1 << " " << 2 << "\n";
      }
    } else {
      cout << -1 << "\n";
    }
    return 0;
  }

  // n >= 3

  vector<int> ans = {1, 2};
  freq[3]++;
  int cur = 3;
  for (int i = 2; i < n; i++) {
    if (freq[cur] <= m) {
      m -= freq[cur];
      for (int j = 0; j < i; j++) {
        freq[ans[j] + cur]++;
      }
      while (!freq.empty() && begin(freq)->first <= cur) {
        freq.erase(begin(freq));
      }
      ans.emplace_back(cur);
      if (freq.upper_bound(cur) == end(freq)) {
        break;
      }
      cur = freq.upper_bound(cur)->first;
    } else {
      while (!freq.empty() && begin(freq)->first <= cur) {
        freq.erase(begin(freq));
      }
      if (freq.upper_bound(cur) == end(freq)) {
        break;
      }
      cur = freq.upper_bound(cur)->first;
      i--;
    }
  }
  
  if (m > 0) {
    cout << -1 << "\n";
    return 0;
  }

  int cnt = 0;
  while (ans.size() < n) {
    ans.emplace_back(5e8 + cnt);
    cnt += cur + 1;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}