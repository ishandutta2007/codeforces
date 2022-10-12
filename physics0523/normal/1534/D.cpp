#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int n;

vector<int> query(int x){
  cout << "? " << x+1 << '\n';
  fflush(stdout);
  vector<int> res(n);
  for(auto &nx : res){cin >> nx;}
  return res;
}

int main(){
  cin >> n;
  vector<vector<int>> a(n);
  a[0]=query(0);
  set<pi> res;
  vector<int> gs,ks;
  for(int i=0;i<n;i++){
    if(a[0][i]%2){ks.push_back(i);}
    else{gs.push_back(i);}
  }
  if(gs.size()>ks.size()){swap(gs,ks);}
  for(auto &nx : gs){
    if(nx==0){continue;}
    a[nx]=query(nx);
  }
  for(auto &nx : gs){
    for(int i=0;i<n;i++){
      if(a[nx][i]==1){
        int mi=min(nx,i),ma=max(nx,i);
        res.insert({mi,ma});
      }
    }
  }
  cout << "!\n";
  for(auto &nx : res){cout << nx.first+1 << ' ' << nx.second+1 << '\n';}
  fflush(stdout);
  return 0;
}