#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<vector<bool>> fl(k+1,vector<bool>(k+1,false));
  fl[0][0]=true;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    vector<vector<bool>> nfl=fl;
    for(int x=0;x<=k;x++){
      for(int y=0;y<=k-v;y++){
        if(!fl[x][y]){continue;}
        nfl[x][y+v]=true;
        nfl[x+v][y+v]=true;
      }
    }
    fl.swap(nfl);
  }

  vector<int> res;
  for(int i=0;i<=k;i++){
    if(fl[i][k]){res.push_back(i);}
  }
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}