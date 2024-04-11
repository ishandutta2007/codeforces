#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n;
char s[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  
  vector<pair<string, int>> v;
  
  for (int k = 0; k < n; ++k) {
    string ss;
    for (int i = k; i < n; ++i) {
      ss += s[i];
    }
    
    if (n - k & 1) {
      for (int i = k-1; i >= 0; --i) ss += s[i];
    } else {
      for (int i = 0; i < k; ++i) ss += s[i];
    }
    
    v.push_back({ss, k});
  }
  
  sort(v.begin(), v.end());
  
  cout << v[0].first << "\n" << v[0].second + 1 << "\n";
  
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}