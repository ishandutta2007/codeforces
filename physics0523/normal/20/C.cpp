#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;
using pl=pair<long long,long long>;
using Graph=vector<vector<pl>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  Graph g(n+1);
  for(int i=0;i<m;i++){
    long long a,b,c;
    cin >> a >> b >> c;
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
  }
  vector<long long> dist(n+1,llinf);
  vector<long long> back(n+1,-1);
  vector<bool> fl(n+1);
  priority_queue<pl,vector<pl>,greater<pl>> pq;
  pq.push(make_pair(0,1));
  dist[1]=0;
  while(!pq.empty()){
    pl od=pq.top();
    pq.pop();
    if(fl[od.second]){continue;}
    fl[od.second]=true;
    for(auto &nx : g[od.second]){
      long long nd=od.first+nx.second;
      long long nv=nx.first;
      if(nd<dist[nv]){
        dist[nv]=nd;
        back[nv]=od.second;
        pq.push(make_pair(nd,nv));
      }
    }
  }
  if(!fl[n]){cout << "-1\n";return 0;}
  vector<long long> res;
  long long cv=n;
  while(cv!=-1){
    res.push_back(cv);
    cv=back[cv];
  }
  reverse(res.begin(),res.end());
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}