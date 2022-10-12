#include<bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(c==0){
    if(a==b){cout << "YES\n";}
    else{cout << "NO\n";}
    return 0;
  }
  int d=(b-a);
  if(d%c==0 && d/c>=0){cout << "YES\n";}
  else{cout << "NO\n";}
  return 0;
}