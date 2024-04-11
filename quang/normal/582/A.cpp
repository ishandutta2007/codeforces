#include <bits/stdc++.h>

using namespace std;

multiset<int> s;
int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n * n; i++) {
    int u;
    cin >> u;
    s.insert(-u);
  }
  vector <int> res;
  while (!s.empty()) {
    int u = - (*s.begin());
    s.erase(s.begin());
    for (int i = 0; i < res.size(); i++) {
      int x = __gcd(res[i], u);
      s.erase(s.find(-x));
      s.erase(s.find(-x));
    }
    res.push_back(u);
  }
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}