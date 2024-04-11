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
    int o=0,e=0,gen=1e9;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v&1){o++;}else{e++;}
      int c=0;
      while(!(v&1)){v>>=1;c++;}
      gen=min(gen,c);
    }
    if(o!=0){cout << e << '\n';}
    else{cout << e+gen-1 << '\n';}
  }
  return 0;
}