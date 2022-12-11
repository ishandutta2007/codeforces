#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int s = 0;
  int l = 2e9;
  int k;
  for(int j = 0;j<n;j++){
    cin >> k;
    if(k%2)l=min(l,k);
    s += k;
  }
  if(s%2==0){
    if(l==2e9){
      cout << 0 << "\n"; 
      return 0;
    }
    s-=l;
  }
  cout << s;
  return 0;
}