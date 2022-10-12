#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int od=0,ev=0;
    for(int i=0;i<2*n;i++){
      int v;
      cin >> v;
      if(v%2){od++;}else{ev++;}
    }
    if(od==n && ev==n){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}