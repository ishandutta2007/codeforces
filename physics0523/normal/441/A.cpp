#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,v;
  cin >> n >> v;
  vector<int> res;
  for(int i=1;i<=n;i++){
    int c;
    cin >> c;
    bool ok=false;
    for(int j=0;j<c;j++){
      int w;
      cin >> w;
      if(w<v){ok=true;}
    }
    if(ok){res.push_back(i);}
  }
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}