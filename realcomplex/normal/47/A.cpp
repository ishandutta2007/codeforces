#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int l = 0,r = 1;
  while(l<n){
    l+=r;
    ++r;
  }
  cout << ((l==n) ? "YES\n" : "NO\n");
  return 0;
}