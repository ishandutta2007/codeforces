#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x,y,z;
  int a,b,c;

  cin >> x >> y >> z;
  cin >> a >> b >> c;
  if(x>a){cout << "NO\n";}
  else if((x+y)>(a+b)){cout << "NO\n";}
  else if((x+y+z)>(a+b+c)){cout << "NO\n";}
  else{cout << "YES\n";}
  return 0;
}