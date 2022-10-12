#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<vector<int>> a(n,vector<int>(n));
  vector<string> s(n);
  vector<pi> mem(n*n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      a[i][j]--;
      s[i].push_back('-');
      mem[a[i][j]]={i,j};
    }
  }
  int sumi=-1e9,suma=1e9;
  int dimi=-1e9,dima=1e9;
  for(int v=n*n-1;v>=0;v--){
    int p=mem[v].first;
    int q=mem[v].second;
    int sum=p+q;
    int dif=p-q;
    if(sumi<=sum && sum<=suma && dimi<=dif && dif<=dima){
      s[p][q]='M';
      sumi=max(sum-k,sumi);
      suma=min(sum+k,suma);
      dimi=max(dif-k,dimi);
      dima=min(dif+k,dima);
    }
    else{
      s[p][q]='G';
    }
  }
  for(auto &nx : s){cout << nx << '\n';}
  return 0;
}