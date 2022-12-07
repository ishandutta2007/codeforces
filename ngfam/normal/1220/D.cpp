#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector < long long > a(n + 1);

  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  long long lim = 1e18;

  vector < int > ans(n);

  for(long long b = 1; b <= lim; b *= 2) {
    vector < int > vec;
    for(int i = 1; i <= n; ++i) {
      if(a[i] % b == 0 && (a[i] / b) % 2 == 1) {
      }
      else vec.push_back(i);
    }
    if(vec.size() < ans.size()) ans = vec;
  }

  cout << ans.size() << endl;
  for(auto x : ans) cout << a[x] << " ";

  return 0;
}