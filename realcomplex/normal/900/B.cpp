#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;  
  for(int i = 1;i<=1e5;i++){
    a *= 10;
    if(a/b==c){
      cout << i << "\n";
      exit(0);
    }
    a %= b;
  } 
  cout << -1;
  return 0;
}