#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;
using plp=pair<long long,pl>;
using Graph=vector<vector<plp>>;

long long llzt(long long a,long long b){return max(a,b)-min(a,b);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  Graph g(n+1);
  vector<long long> w(m+1);
  for(int i=1;i<=m;i++){
    long long u,v;
    cin >> u >> v >> w[i];
    g[u].push_back(make_pair(v,make_pair(w[i],i)));
    g[v].push_back(make_pair(u,make_pair(w[i],i)));
  }
  vector<long long> res;
  priority_queue<pl,vector<pl>,greater<pl>> pq;
  long long st;
  cin >> st;
  vector<long long> dist(n+1,-1);
  pq.push(make_pair(0,st));
  while(!pq.empty()){
    pl od=pq.top();pq.pop();
    long long cv=od.second;
    long long cd=od.first;
    if(dist[cv]!=-1){continue;}
    dist[cv]=cd;
    for(auto &nx : g[cv]){
      long long nv=nx.first;
      long long nl=nx.second.first;
      if(dist[nv]!=-1){continue;}
      pq.push(make_pair(cd+nl,nv));
    }
  }

  vector<bool> fl(n+1);
  vector<pl> arr(n);
  for(int i=0;i<n;i++){arr[i].first=dist[i+1];arr[i].second=i+1;}
  sort(arr.begin(),arr.end());
  fl[st]=true;
  for(int i=1;i<n;i++){
    long long cv=arr[i].second;
    long long rid=-1,rl=1000000007;
    for(auto &nx : g[cv]){
      long long nv=nx.first;
      long long nl=nx.second.first;
      long long nid=nx.second.second;
      if(fl[nv]){
        //cout << cv << "->" << nv << ' ' << dist[nv]+nl << ' ' << dist[cv] << '\n';
        if(dist[nv]+nl!=dist[cv]){continue;}
        if(rl>nl){rl=nl;rid=nid;}
      }
    }
    res.push_back(rid);
    fl[cv]=true;
  }

  long long rw=0;
  for(auto &nx : res){rw+=w[nx];}
  cout << rw << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }
  return 0;
}