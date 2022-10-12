#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,h;
  cin >> n >> m >> h;
  vector<int> b(m),a(n);
  for(auto &nx : b){cin >> nx;}
  for(auto &nx : a){cin >> nx;}
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(j){cout << ' ';}
      int v;
      cin >> v;
      if(v){cout << min(a[i],b[j]);}
      else{cout << "0";}
    }cout << '\n';
  }
  return 0;
}