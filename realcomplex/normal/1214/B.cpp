#include <bits/stdc++.h>

using namespace std;

int main(){
  int b, g, n;
  cin >> b >> g >> n;
  b = min(b, n);
  g = min(g, n);
  int res = 0;
  int f;
  for(int i = 0 ; i <= b; i ++ ){
    f = n - i;
    res += (f <= g);
  }
  cout << res << "\n";
  return 0;
}