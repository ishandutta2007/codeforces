#include<bits/stdc++.h>

using namespace std;

void mg(vector<int> &mg,vector<int> &rm){
  if(mg.size()<rm.size()){
    mg.swap(rm);
  }
  for(auto &nx : rm){mg.push_back(nx);}
  rm.clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  int sz=0;
  vector<vector<int>> act(524288);
  while(q>0){
    q--;
    int t;
    cin >> t;
    if(t==1){
      int x;
      cin >> x;
      act[x].push_back(sz);
      sz++;
    }
    else{
      int x,y;
      cin >> x >> y;
      if(x==y){continue;}
      mg(act[y],act[x]);
    }
  }
  vector<int> res(sz);
  for(int i=0;i<524288;i++){
    for(auto &nx : act[i]){
      res[nx]=i;
    }
  }
  for(int i=0;i<sz;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}