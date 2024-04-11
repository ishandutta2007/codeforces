#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
      if(i!=1){cout << " ";}
      cout << 1+(i%n);
    }cout << "\n";
  }
  return 0;
}