#include<bits/stdc++.h>

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
    int n;
    cin >> n;
    vector<int> b(n+1);
    int k=0;
    for(int i=1;i<=n;i++){
      cin >> b[i];
      if(i<b[i]){k=i;}
    }

    cout << k << "\n";
    Graph g(n+1);
    vector<int> arrow(n+1,0);
    for(int i=1;i<=n;i++){
      if(b[i]==0 || b[i]==(n+1)){continue;}
      g[b[i]].push_back(i);
      arrow[i]++;
    }

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=1;i<=n;i++){
      if(arrow[i]==0){
        pq.push({g[i].size(),i});
      }
    }
    vector<int> a;
    while(!pq.empty()){
      pi od=pq.top();pq.pop();
      a.push_back(od.second);
      for(auto &nx : g[od.second]){
        arrow[nx]--;
        if(arrow[nx]==0){
          pq.push({g[nx].size(),nx});
        }
      }
    }

    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << a[i];
    }cout << "\n";
  }
  return 0;
}