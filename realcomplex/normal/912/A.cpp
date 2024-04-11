#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll a,b,x,y,z;
  cin >> a >> b >> x >> y >> z;
  ll blu = (z*3)+y;
  ll yel = (x*2)+y;
  ll ans = max(0LL,yel-a)+max(0LL,blu-b);
  cout << ans;
  return 0;
}