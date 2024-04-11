#include <bits/stdc++.h>

using namespace std;

string a;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  cin >> a;
  int pos = 0;
  while(pos < a.size() && a[pos] == 'a'){
    ++pos;
  }
  if(pos < a.size()){
    while(pos < a.size() && a[pos] != 'a'){
      --a[pos];
      ++pos;
    }
  }
  else{
    a[a.size() - 1] = 'z';
  }
  cout << a;
  return 0;
}