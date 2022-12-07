#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  int k, a, b;
  cin >> k >> a >> b;
  int wa = a / k, wb = b / k;
  if((a % k > 0 && wb == 0) || (b % k > 0 && wa == 0)){
    cout << "-1";
    return 0;
  }
  cout << wa + wb;
  return 0;
}