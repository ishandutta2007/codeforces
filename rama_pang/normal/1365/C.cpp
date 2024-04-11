#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }  
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[b[i]] = i;
  }

  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    f[(pos[a[i]] - i + n) % n]++;
  }
  cout << *max_element(begin(f), end(f)) << "\n";
  return 0;
}