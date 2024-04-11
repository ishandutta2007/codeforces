#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> cand(n,(1<<30)-1);
  vector<int> res(n,0);

  vector<int> p(m),q(m),x(m);
  Graph g(n);
  for(int i=0;i<m;i++){
    cin >> p[i] >> q[i] >> x[i];
    p[i]--;q[i]--;
    if(p[i]>q[i]){swap(p[i],q[i]);}

    g[p[i]].push_back(i);
    cand[p[i]]&=x[i];
    cand[q[i]]&=x[i];
  }

  // for(int i=0;i<n;i++){
  //   cout << cand[i] << " ";
  // }cout << "\n";

  for(int i=0;i<n;i++){
    int apply=0;
    for(auto &nx : g[i]){
      apply|=(x[nx]&(~cand[q[nx]]));
    }
    res[i]|=apply;
    for(auto &nx : g[i]){
      res[q[nx]]|=(x[nx]&(~res[i]));
    }
  }

  for(int i=0;i<n;i++){
    if(i){cout << " ";}
    cout << res[i];
  }cout << "\n";
  return 0;
}