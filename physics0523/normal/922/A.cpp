#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x,y;
  cin >> x >> y;
  if((x+y)%2==0){cout << "No\n";return 0;}
  if(y==0){cout << "No\n";return 0;}
  if(y==1){
    if(x==0){cout << "Yes\n";return 0;}
    else{cout << "No\n";return 0;}
  }
  x-=(y-1);
  if(x<0 || x%2==1){cout << "No\n";return 0;}
  cout << "Yes\n";
  return 0;
}