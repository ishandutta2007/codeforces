#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<vector<int>> cyclist(int n,Graph &g){
  vector<vector<int>> res;
  vector<bool> fl(n,false);
  for(int i=0;i<n;i++){
    if(fl[i]){continue;}
    fl[i]=true;
    int v=i,pv=-1;
    vector<int> cc={v};
    do{
      int nv=-1;
      for(auto &nx : g[v]){
        if(nx==pv){continue;}
        nv=nx;
      }
      pv=v;
      v=nv;
      fl[nv]=true;
      cc.push_back(nv);
    }while(v!=i);
    res.push_back(cc);
  }
  return res;
}

long long n;
void app(long long x,long long &ll,long long &lr,long long &rl,long long &rr){
  if(x<n){
    ll=min(ll,x);
    lr=max(lr,x);
  }
  else{
    rl=min(rl,x);
    rr=max(rr,x);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  Graph g(2*n);
  for(int i=0;i<2*n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<int>> cl=cyclist(2*n,g);
  long long res=0;
  for(auto &nx : cl){
    int en=(nx.size()-1);
    for(int i=0;i<en;i++){
      long long ll=1e9,lr=-1e9;
      long long rl=1e9,rr=-1e9;
      for(int j=0;j<en;j++){
        int eid=(i+j)%en;
        app(nx[eid],ll,lr,rl,rr);
        app(nx[eid+1],ll,lr,rl,rr);
        long long dlt=(ll+1)*(n-lr)*((rl-n)+1)*(2*n-rr);
        //cout << dlt << '\n';
        if(j%2==0){res+=dlt;}
        else{res-=dlt;}
      }
      if(i==0){
        long long ce=(en/2);
        res+=ce*(ll+1)*(n-lr)*((rl-n)+1)*(2*n-rr);
      }
    }
    // for(auto &ny : nx){
    //   cout << ny << ' ';
    // }cout << '\n';
  }
  cout << res << '\n';
  return 0;
}