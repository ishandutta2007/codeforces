#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for(int l=0;l<t;l++){
    int N,a,b,da,db;
    cin>>N>>a>>b>>da>>db;
    a--,b--;
    vector<vector<int>> G(N);
    for(int i=0;i<N-1;i++){
      int x,y;
      cin>>x>>y;
      x--,y--;
      G[y].push_back(x);
      G[x].push_back(y);
    }
    queue<int> q;
    vector<int> seen(N,-1);
    vector<int> em(N,-1);
    seen[a]=0;
    q.push(a);
    int X;
    while(!q.empty()){
      X=q.front();
      q.pop();
      for(auto x:G[X]){
        if(seen[x]==-1){
          seen[x]=seen[X]+1;
          q.push(x);
        }
      }
    }
    int D=seen[b],Z=0;
    seen=em;
    seen[X]=0;
    q.push(X);
    while(!q.empty()){
      X=q.front();
      q.pop();
      for(auto x:G[X]){
        if(seen[x]==-1){
          seen[x]=seen[X]+1;
          q.push(x);
          Z=seen[x];
        }
      }
    }
    if(da<D&&da*2<min(Z,db)){
      cout<<"Bob"<<endl;
    }
    else{
      cout<<"Alice"<<endl;
    }
  }
}