#include <bits/stdc++.h>
using namespace std;

int n;

int solve() {
  scanf("%d", &n);
  
  int a[7];
  for (int i=0; i<7; i++) scanf("%d", a + i);
  
  vector<int> v;
  int sum = 0;
  for (int i=0; i<7; i++) {
    if (a[i]) {
      sum += a[i];
      v.push_back(i);
    }
  }
  int ans = 1000000000;
  for (int i=0; i<v.size(); i++) {
    int m = n % sum;
    int d = n / sum;
    
    if (m > 0) {
      ans = min(ans, d*7 + (v[(i + m - 1 + v.size()) % v.size()] - v[i] + 8) % 7);
    } else {
      // cerr << d << " " << v[i] << " " << v[(i+v.size() - 1)%v.size()] << " " << d*7 - (v[i] - v[(i+v.size() - 1)%v.size()] + 6) % 7 << endl;
      ans = min(ans, d*7 - (v[i] - v[(i+v.size() - 1)%v.size()] + 6) % 7);
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  
  return 0;
}