#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int r;
int rep(int d,int v,int pv,vector<int> &a,Graph &g){
  r=max(r,d);
  priority_queue<int,vector<int>,greater<int>> pq;
  pq.push(0);
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    pq.push(rep(d+1,nx,v,a,g));
    while(pq.size()>2){pq.pop();}
  }
  int p=-1,q=-1;
  if(pq.size()==2){q=pq.top();pq.pop();}
  p=pq.top();pq.pop();
  if((d+q-1)>0){a[d+q-1]=max(a[d+q-1],(p+q+1)/2);}
  return p+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    Graph g(n);
    for(int i=1;i<n;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> a(n,0);
    r=0;
    rep(0,0,-1,a,g);
    for(int i=n-2;i>=0;i--){a[i]=max(a[i],a[i+1]);}
    int cans=1;
    for(int x=1;x<=n;x++){
      if(x-1){cout << ' ';}
      while(cans<(n-1) && min(r,x+a[cans])>cans){cans++;}
      cout << cans;
    }cout << '\n';
  }
  return 0;
}