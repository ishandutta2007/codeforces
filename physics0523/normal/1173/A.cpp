#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int p,m,q;
  cin >> p >> m >> q;
  int mi=p-m-q;
  int ma=p-m+q;
  if(ma<0){cout << "-\n";}
  else if(mi>0){cout << "+\n";}
  else if(mi==0 && ma==0){cout << "0\n";}
  else{cout << "?\n";}
  return 0;
}