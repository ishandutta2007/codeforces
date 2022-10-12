#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a,b,x,y;
  cin >> a >> b >> x >> y;
  long long g=gcd(x,y);
  x/=g;y/=g;
  cout << min(a/x,b/y) << '\n';
  return 0;
}