#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

void rep(int v,int cc,vector<int> &col,Graph &g){
  col[v]=cc;
  for(auto &nx : g[v]){
    if(col[nx]!=-1){continue;}
    rep(nx,1-cc,col,g);
  }
}

long long par(long long x){
  if(x%2==0){return 0;}else{return 1;}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<long long> v(n),t(n);
    Graph g(n);
    for(int i=0;i<n;i++){cin >> v[i];}
    for(int i=0;i<n;i++){cin >> t[i];}
    vector<pi> eg;
    for(int i=0;i<m;i++){
      int p,q;
      cin >> p >> q;
      p--;q--;
      eg.push_back({p,q});
      g[p].push_back(q);
      g[q].push_back(p);
    }
    vector<int> col(n,-1);
    rep(0,0,col,g);
    bool isb=true;
    for(auto &nx : eg){
      //cerr << nx.first << ',' << nx.second << '\n';
      //cerr << col[nx.first] << ',' << col[nx.second] << '\n';
      if(col[nx.first]==col[nx.second]){isb=false;}
    }
    if(isb){
      //for(int i=0;i<n;i++){cout << col[i] << '\n';}
      long long p1=0,p2=0;
      for(int i=0;i<n;i++){
        if(col[i]==0){p1+=v[i];p1-=t[i];}
        else{p2+=v[i];p2-=t[i];}
      }
      if(p1==p2){cout << "YES\n";}
      else{cout << "NO\n";}
    }
    else{
      long long p1=0;
      for(int i=0;i<n;i++){p1+=v[i];p1-=t[i];}
      if(par(p1)==0){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }
  return 0;
}