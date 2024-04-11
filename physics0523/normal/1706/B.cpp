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
    vector<vector<int>> mem(n);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mem[v-1].push_back(i);
    }

    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      int o=0,e=0;
      for(auto &nx : mem[i]){
        if(nx%2){o=max(o,e+1);}
        else{e=max(e,o+1);}
      }
      cout << max(o,e);
    }cout << "\n";
  }
  return 0;
}