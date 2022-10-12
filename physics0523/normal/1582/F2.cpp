#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<queue<int>> wl(5005);
  vector<vector<bool>> fl(5005,vector<bool>(8192,false));
  for(int i=0;i<5005;i++){
    wl[i].push(0);
    fl[i][0]=true;
  }
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    while(!wl[v].empty()){
      int od=wl[v].front();wl[v].pop();
      for(int j=v+1;j<5005;j++){
        if(fl[j][od^v]){break;}
        fl[j][od^v]=true;
        wl[j].push(od^v);
      }
    }
  }
  vector<int> res;
  for(int i=0;i<8192;i++){
    if(fl[5004][i]){res.push_back(i);}
  }
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}