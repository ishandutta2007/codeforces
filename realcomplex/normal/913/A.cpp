#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  if(n>=30){
    cout << m << "\n";
    return 0;
  }
  int k = 1;
  for(int j = 1;j<=n;j++){
    k*=2;
  }
  cout << m%k << "\n";
  return 0;
}