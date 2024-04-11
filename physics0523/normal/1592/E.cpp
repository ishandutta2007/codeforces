#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> death(32,0);
  vector<vector<vector<int>>> mem(20);
  for(int i=0;i<20;i++){
    mem[i].resize(1<<(19-i));
    for(int j=0;j<(1<<(19-i));j++){
      mem[i][j].resize(2);
      mem[i][j][0]=-1;
      mem[i][j][1]=-1;
    }
    mem[i][0][0]=0;
  }
  int res=0,rx=0;
  for(int i=1;i<=n;i++){
    int v;
    cin >> v;
    rx^=v;
    for(int j=0;j<20;j++){
      if((v&(1<<j))==0){death[j]=i;}
      if(mem[j][(rx>>(j+1))][i%2]<death[j]){
        mem[j][(rx>>(j+1))][i%2]=i;
      }
      if((v&(1<<j))){
        //cerr << i << ' ' << j << ':' << mem[j][(rx>>(j+1))][i%2] << '\n';
        res=max(i-mem[j][(rx>>(j+1))][i%2],res);
      }
    }
  }
  cout << res << '\n';
  return 0;
}