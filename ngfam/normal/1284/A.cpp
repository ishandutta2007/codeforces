#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector < string > s(n), t(m);

  for(auto &x : s) cin >> x;
  for(auto &y : t) cin >> y;

  int q; cin >> q;
  while(q--) {
    int x; cin >> x;
    x--;
    cout << s[x % n] << t[x % m] << endl;
  }

  return 0;
}