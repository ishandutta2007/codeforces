#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  vector<int> a(n);
  for (int i=0; i < n; i++) cin>>a[i];
  
  int res = -(int)2e9;
  for (int i=0; i < n; i++) {
    for (int j=i; j < n; j++) {
      vector<int> x, y;
      for (int k=0; k < n; k++)
      if (i <= k && k <= j) {
        x.push_back(a[k]);
      } else {
        y.push_back(a[k]);
      }        
      sort(x.begin(), x.end());
      sort(y.begin(), y.end()); reverse(y.begin(), y.end());
      for (int t=0; t < k && t < (int)x.size() && t < (int)y.size() && x[t] < y[t]; t++) {
        swap(x[t], y[t]);
      }
      int sum = 0;
      for (int k=0; k < (int)x.size(); k++) {
        sum += x[k];
      }
      res = max(res, sum);
    }
  }
  cout << res << endl;
}