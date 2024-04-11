#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> u(n-1),v(n-1);
  vector<int> bk(n+1,0);
  for(int i=0;i<n-1;i++){
    cin >> u[i] >> v[i];
    bk[u[i]]++;
    bk[v[i]]++;
  }
  int tg=-1;
  for(int i=1;i<=n;i++){
    if(bk[i]>=3){tg=i;break;}
  }
  vector<int> res(n-1,-1);
  int id=0;
  for(int i=0;i<n-1;i++){
    if(u[i]==tg || v[i]==tg){
      res[i]=id;id++;
    }
  }
  for(int i=0;i<n-1;i++){
    if(res[i]<0){
      res[i]=id;
      id++;
    }
  }
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}