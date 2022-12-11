#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, d, e;
  cin >> n >> d >> e;
  e *= 5;
  int res = n;
  int f = 0;
  while(f <= n){
    res = min(res, (n - f) % d);
    f += e;
  }
  cout << res;
  return 0;
}