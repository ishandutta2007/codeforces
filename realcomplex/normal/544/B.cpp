#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int w=n*n;
  w=(w/2)+(w%2);
  if(k>w){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++){
      if(i%2==j%2 and k>0){
        cout << "L";
        --k;
      }
      else cout << "S";
    }
    cout << "\n";
  }
  return 0;
}