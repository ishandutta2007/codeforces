#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int solve(int n,int p,vector<int> a,vector<int> bk,Graph g){
  int cnt=0,res=0;
  vector<vector<int>> atk(3);
  for(int i=0;i<n;i++){
    if(bk[i]==0){
      atk[a[i]].push_back(i);
    }
  }
  while(cnt<n){
    while(!atk[p].empty()){
      int od=atk[p].back();
      atk[p].pop_back();
      cnt++;res++;
      for(auto &nx : g[od]){
        bk[nx]--;
        if(bk[nx]==0){
          atk[a[nx]].push_back(nx);
        }
      }
    }
    if(cnt==n){break;}
    p++;p%=3;res++;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){
    cin >> nx;
    nx--;
  }
  vector<int> bk(n,0);
  Graph g(n);
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    for(int j=0;j<k;j++){
      int v;
      cin >> v;
      v--;
      g[v].push_back(i);
      bk[i]++;
    }
  }
  int res=1e9;
  for(int i=0;i<3;i++){
    res=min(solve(n,i,a,bk,g),res);
  }
  cout << res << "\n";
  return 0;
}