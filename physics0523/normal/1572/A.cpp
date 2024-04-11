#include<bits/stdc++.h>

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
    vector<int> d(n,0);
    Graph g(n);
    for(int i=0;i<n;i++){
      cin >> d[i];
      for(int j=0;j<d[i];j++){
        int v;
        cin >> v;
        v--;
        g[v].push_back(i);
      }
    }
    deque<int> q;
    for(int i=0;i<n;i++){
      if(d[i]==0){q.push_back(i);}
    }
    vector<int> l(n,1);
    int cnt=0;
    while(!q.empty()){
      int od=q.front();q.pop_front();
      //cout << od << ' ' << l[od] << '\n';
      cnt++;
      for(auto &nx : g[od]){
        int del;
        if(od<nx){del=0;}else{del=1;}
        l[nx]=max(l[nx],l[od]+del);
        d[nx]--;
        if(d[nx]==0){
          if(del==0){q.push_front(nx);}
          else{q.push_back(nx);}
        }
      }
    }
    if(cnt==n){
      int res=0;
      for(int i=0;i<n;i++){res=max(l[i],res);}
      cout << res << '\n';
    }
    else{cout << "-1\n";}
  }
  return 0;
}