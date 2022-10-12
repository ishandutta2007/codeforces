#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    Graph g(n),exg(2*n);
    vector<int> u(m),v(m);
    for(int i=0;i<m;i++){
      cin >> u[i] >> v[i];
      u[i]--;v[i]--;
      g[u[i]].push_back(v[i]);
    }
    vector<int> d(n,inf);
    queue<int> q;
    d[0]=0;
    q.push(0);
    while(!q.empty()){
      int od=q.front();
      q.pop();
      for(auto &nx : g[od]){
        if(d[nx]!=inf){continue;}
        d[nx]=d[od]+1;
        q.push(nx);
      }
    }

    for(int i=0;i<m;i++){
      if(d[u[i]]<d[v[i]]){
        exg[v[i]].push_back(u[i]);
        exg[n+v[i]].push_back(n+u[i]);
      }
      else{
        exg[v[i]].push_back(n+u[i]);
      }
    }
    vector<int> res(2*n,inf);
    vector<pi> pv;
    for(int i=0;i<2*n;i++){pv.push_back({d[i%n],i});}
    sort(pv.begin(),pv.end());
    for(auto &np : pv){
      if(res[np.second]!=inf){continue;}
      res[np.second]=np.first;
      q.push(np.second);
      while(!q.empty()){
        int od=q.front();
        q.pop();
        for(auto &nx : exg[od]){
          if(res[nx]==inf){
            res[nx]=np.first;
            q.push(nx);
          }
        }
      }
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << min(res[i],res[n+i]);
    }cout << '\n';
  }
  return 0;
}