#include <bits/stdc++.h>

using namespace std;

int pw;

int main(){
  int n,x;
  cin >> n >> x;
  if(n==2 and x==0){
    cout << "NO\n";
    return 0;
  }
  else if(n==1){
    cout << "YES\n" << x << "\n";
  }
  else if(n==2){
    cout << "YES\n0 " << x << "\n";
  }
  else{
  cout << "YES\n";
  int y = 0;
  pw=(1<<17);
  for(int i = 1;i<=n-3;i++){
    y^=i;
    cout << i << " ";
  }
  if(x==y){
    cout << pw << " " << pw*2 << " " << (pw^(pw*2));
  } 
  else{
    cout << 0 << " " << pw << " " << ((pw^x)^y);
  } 
  cout << "\n";
  }
  return 0;
}