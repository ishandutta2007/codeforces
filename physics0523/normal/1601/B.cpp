#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+1),b(n+1);
  for(int i=1;i<=n;i++){cin >> a[i];}
  for(int i=1;i<=n;i++){cin >> b[i];}
  Graph g(2*(n+1));
  int bas=n+1;
  for(int i=1;i<=n;i++){
    g[bas+i-1].push_back({bas+i,0});
  }
  for(int i=1;i<=n;i++){
    g[i].push_back({bas+(i-a[i]),1});
  }
  for(int i=1;i<=n;i++){
    g[bas+i].push_back({i+b[i],0});
  }
  vector<int> d(2*(n+1),0),pv(2*(n+1),-2);
  deque<pi> dq;
  dq.push_back({n,-1});
  while(!dq.empty()){
    pi od=dq.front();dq.pop_front();
    //cerr << od.first << ',' << od.second << '\n';
    int cv=od.first;
    if(pv[cv]!=-2){continue;}
    pv[cv]=od.second;
    for(auto &nx : g[cv]){
      d[nx.first]=min(d[nx.first],d[cv]+nx.second);
      pi pd={nx.first,cv};
      if(nx.second==0){
        dq.push_front(pd);
      }
      else{
        dq.push_back(pd);
      }
    }
  }
  if(pv[bas]==-2){cout << "-1\n";return 0;}
  vector<int> arr;
  int v=bas;
  while(v!=-1){
    arr.push_back(v);
    v=pv[v];
  }
  reverse(arr.begin(),arr.end());
  vector<int> res;
  for(int i=0;i<arr.size()-1;i++){
    if(arr[i]>=bas && arr[i+1]<bas){
      res.push_back(arr[i]-bas);
    }
  }
  res.push_back(0);
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}