#include <bits/stdc++.h>

using namespace std;

int main(){
  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int y, b, r;
  cin >> y >> b >> r;
  
  y = min(y, min(b - 1, r - 2)) + 1;
  cout << 3 * y;
  
  return 0;
}