#include<bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  for(int i=1;i<1000;i++){
    a*=10;
    if(c==(a/b)){cout << i << '\n';return 0;}
    a%=b;
  }
  cout << "-1\n";
  return 0;
}