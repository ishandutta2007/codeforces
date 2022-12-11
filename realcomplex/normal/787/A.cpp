#include <bits/stdc++.h>

using namespace std;

bitset<1000999>is;

int main(){
  int a,b,c,d;
  cin >> b >> a >> d >> c;
  for(int i = 0;i<=10000;i++){
    is[a+(b*i)]=1;
  }
  for(int j = 0;j<=10000;j++){
    if(is[c+(j*d)]==1){
      cout << c+(j*d) << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}