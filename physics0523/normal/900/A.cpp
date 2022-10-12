#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int p=0,q=0;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    if(a>0){p++;}else{q++;}
  }
  if(p<=1 || q<=1){cout << "Yes\n";return 0;}
  else{cout << "No\n";return 0;}
  return 0;
}