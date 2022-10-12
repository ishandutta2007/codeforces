#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<vector<int>> mem(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    for(int j=0;j<v;j++){mem[i][j]|=2;}
    if(v<m){mem[i][v]|=1;}
  }
  for(int j=0;j<m;j++){
    int v;
    cin >> v;
    for(int i=0;i<v;i++){mem[i][j]|=2;}
    if(v<n){mem[v][j]|=1;}
  }
  int res=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mem[i][j]==3){res*=0;}
      if(mem[i][j]==0){res*=2;}
      res%=mod;
    }
  }
  cout << res << '\n';
  return 0;
}