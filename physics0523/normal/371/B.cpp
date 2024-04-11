#include<bits/stdc++.h>

using namespace std;

map<int,int> calc(int x){
  map<int,int> res;
  queue<int> q;
  q.push(x);
  res[x]=0;
  while(!q.empty()){
    int od=q.front();q.pop();
    if(od%2==0){
      if(res[od/2]==0){
        res[od/2]=res[od]+1;
        q.push(od/2);
      }
    }
    if(od%3==0){
      if(res[od/3]==0){
        res[od/3]=res[od]+1;
        q.push(od/3);
      }
    }
    if(od%5==0){
      if(res[od/5]==0){
        res[od/5]=res[od]+1;
        q.push(od/5);
      }
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b;
  cin >> a >> b;
  map<int,int> am=calc(a);
  map<int,int> bm=calc(b);
  int res=1e9;
  for(auto &nx : am){
    if(bm.find(nx.first)!=bm.end()){
      res=min(res,nx.second+bm[nx.first]);
    }
  }
  if(res>5e8){res=-1;}
  cout << res << '\n';
  return 0;
}