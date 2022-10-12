#include<bits/stdc++.h>

using namespace std;

int main(){
  long long n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  long long mi=min({a+c,c+d,d+b,b+a});
  long long ma=max({a+c,c+d,d+b,b+a});
  long long ce=max(n-(ma-mi),0ll);
  cout << ce*n << '\n';
  return 0;
}