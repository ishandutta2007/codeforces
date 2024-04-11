#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int tv=(1<<n);
    Graph g(tv);
    for(int i=0;i<(n*tv)/2;i++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> rest(tv,0),d(tv,inf);
    queue<int> q;
    q.push(0);
    d[0]=0;
    while(!q.empty()){
      int cv=q.front();q.pop();
      //cout << cv  << ':' << rest[cv] << '\n';
      if(cv==0){
        int fl=1;
        for(auto &nx : g[0]){
          d[nx]=1;
          rest[nx]|=fl;
          fl<<=1;
          q.push(nx);
        }
      }
      else{
        for(auto &nx : g[cv]){
          if((d[cv]+1)>d[nx]){continue;}
          if((d[cv]+1)<d[nx]){
            q.push(nx);
            d[nx]=(d[cv]+1);
          }
          rest[nx]|=rest[cv];
        }
      }
    }
    //for(int i=0;i<tv;i++){cout << rest[i] << '\n';}
    vector<int> res(tv);
    for(int i=0;i<tv;i++){res[rest[i]]=i;}
    for(int i=0;i<tv;i++){
      if(i){cout << ' ';}cout << res[i];
    }cout << '\n';
    if(n!=1 && n!=2 && n!=4 && n!=8 && n!=16){cout << "-1\n";}
    else{
      for(int i=0;i<tv;i++){
        if(i){cout << ' ';}
        int ov=0;
        for(int j=0;j<n;j++){
          if(rest[i]&(1<<j)){ov^=j;}
        }
        cout << ov;
      }
      cout << '\n';
    }
  }
  return 0;
}