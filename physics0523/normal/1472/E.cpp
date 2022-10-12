#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=map<int,vector<pi>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> h(n),w(n);
    vector<int> res(n,-2);
    Graph g;
    for(int i=0;i<n;i++){
      cin >> h[i] >> w[i];
      g[h[i]].push_back({w[i],i});
      g[w[i]].push_back({h[i],i});
    }
    set<pi> st;
    for(auto &nx : g){
      for(auto &nx : nx.second){
        int cw=nx.first;
        if(!st.empty() && (*st.begin()).first<cw){
          res[nx.second]=(*st.begin()).second;
        }
      }
      for(auto &nx : nx.second){
        st.insert(nx);
      }
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i]+1;
    }cout << '\n';
  }
  return 0;
}