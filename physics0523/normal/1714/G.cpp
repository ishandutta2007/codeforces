#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;
using plp=pair<long long,pair<long long,long long>>;
using Graph=vector<vector<plp>>;

Graph g;
vector<long long> res;
set<pl> st;

void rep(long long v,long long d,long long a,long long b){
  auto it=st.lower_bound({a+1,-1e9});
  if(it==st.begin()){
    res[v]=0;
  }
  else{
    it--;
    res[v]=(*it).second;
  }
  // cout << a << " vs ";
  // for(auto &nx : st){
  //   cout << nx.first << " " << nx.second << ",";
  // }
  // cout << v << ":" << res[v] << "\n";
  for(auto &nx : g[v]){
    st.insert({b+nx.second.second,d});
    rep(nx.first,d+1,a+nx.second.first,b+nx.second.second);
    st.erase({b+nx.second.second,d});
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;

    res.resize(n);
    g.resize(n);
    for(long long i=0;i<n;i++){g[i].clear();}
    st.clear();

    for(long long i=1;i<n;i++){
      long long p,a,b;
      cin >> p >> a >> b;
      p--;
      g[p].push_back({i,{a,b}});
    }

    rep(0,1,0,0);
    for(long long i=1;i<n;i++){
      if(i-1){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}