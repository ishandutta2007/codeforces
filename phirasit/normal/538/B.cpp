#include <iostream>
#include <vector>

using namespace std;

int n;
int mx = 0;

int main() {
  cin >> n;
  for(int i = n;i > 0;i /= 10) {
    mx = max(mx, i % 10);
  }
  vector<int> ans(mx, 0);
  for(int i = n, j = 1;i > 0;i /= 10, j *= 10) {
    int digit = i % 10;
    for(int k = 0;k < digit;k++) {
      ans[k] += j;
    }
  }
  cout << ans.size() << endl;
  for(int v : ans) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}