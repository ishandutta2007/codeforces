#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;

  int cnt = 0;
  while(n--) {
    int x; cin >> x;
    if(x % 2 == 0) cout << x / 2 << endl;
    else {
      int sign = x / abs(x);
      int a = x / 2, b = (x + sign) / 2;
      if(a > b) swap(a, b);
      if(++cnt % 2 == 0) cout << a << endl;
      else cout << b << endl;
    }
  }

  return 0;
}