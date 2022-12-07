#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector < int > cnt(1e6 + 5, 0), mark(n + 5, 0);
  vector < vector < int > > a(n);


  int realcnt = 0;
  long long answer = 0;
  for(int i = 0; i < n; ++i) {
    int sz; cin >> sz;
    a[i].resize(sz);
    int mn = 1e9, mx = -1;
    for(int &x : a[i]) {
      cin >> x;
      if(x > mn) {
        mark[i] = 1;
      }
      mx = max(mx, x);
      mn = min(mn, x);
    }
    if(mark[i]) answer += (n - 1 - realcnt) * 2 + 1, ++realcnt;
    else ++cnt[mx];
  }
  for(int i = cnt.size() - 2; i >= 0; --i) {
    cnt[i] += cnt[i + 1];
  }

  for(int i = 0; i < n; ++i) {
    if(mark[i]) continue;
    int mn = 1e9, mx = -1;
    for(int &x : a[i]) {
      cin >> x;
      mx = max(mx, x);
      mn = min(mn, x);
    }
    answer += cnt[mn + 1];
  }

  cout << answer << endl;
  return 0;
}