#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int x, y, z;
  cin >> x >> y >> z;

  int mini = x - y - z, maxi = x - y + z;
  if(mini <= 0 && maxi >= 0 && max(abs(mini), abs(maxi)) > 0) {
    cout << "?"; 
  } 
  else {
    if(maxi == 0) {
      cout << 0;
    }
    else cout << (maxi > 0 ? '+' : '-');
  }

  return 0;
}