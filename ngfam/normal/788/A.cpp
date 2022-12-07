#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  cin >> n;

  vector < int > a(n);
  for(int &x : a) cin >> x;

  long long cur = 0, mx = 0, mn = 0, ans = 0;
  for(int i = n - 2; i >= 0; --i) {
    cur = -cur;
    swap(mx, mn);
    mx = -mx;
    mn = -mn;
    cur += abs(a[i] - a[i + 1]);
    ans = max(ans, cur - mn);
    mx = max(mx, cur);
    mn = min(mn, cur);
  }

  cout << ans << endl;

  return 0;
}