#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(n), s(n);

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    s[i] = a[i];
    if(i > 0) s[i] += s[i - 1];
  }
  string r; cin >> r;

  int all = 0;
  for(int i = n - 1; i >= 0; --i) {
    if(r[i] == '1' && i > 0) {
      ans = max(ans, all + s[i - 1]);
    }
    if(r[i] == '1') {
      all += a[i];
    }
  }

  ans = max(ans, all);

  cout << ans << endl;

  return 0;
}