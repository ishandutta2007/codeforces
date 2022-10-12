#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;
using pl=pair<long long,long long>;
using Graph=vector<vector<pl>>;

long long llceil(long long a,long long b){
  if(b==0){return llinf;}
  if(a%b==0){return a/b;}return (a/b)+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  long long bo,in,da;
  cin >> bo >> in >> da;
  vector<long long> mh(n),sh(n),rg(n);
  Graph g(n);
  for(int i=0;i<n;i++){
    cin >> mh[i] >> sh[i] >> rg[i];
    g[i].push_back(make_pair(0,sh[i]));
    if(mh[i]<=da && in!=0){cout << "-1\n";return 0;}
  }
  for(int i=0;i<m;i++){
    long long t,e,h;
    cin >> t >> e >> h;
    g[e-1].push_back(make_pair(t,h));
  }

  vector<pl> imos;
  for(int i=0;i<n;i++){
    sort(g[i].begin(),g[i].end());
    int cnt=g[i].size();
    int cp=0;
    for(int j=0;j<cnt;j++){
      long long yh=da-g[i][j].second;
      if(yh>=0){
        if(cp==0){
          imos.push_back(make_pair(g[i][j].first,1));
          cp=1;
        }
        if(rg[i]!=0){
          yh++;
          yh=llceil(yh,rg[i]);
          yh+=g[i][j].first;
        }
        else{yh=llinf;}
        if((j==cnt-1 && yh!=llinf) || (j!=cnt-1 && yh<g[i][j+1].first)){
          imos.push_back(make_pair(yh,-1));
          cp=0;
        }
      }
      else{
        if(cp==1){
          imos.push_back(make_pair(g[i][j].first,-1));
          cp=0;
        }
      }
    }
    if(cp==1 && in!=0){cout << "-1\n";return 0;}
  }
  imos.push_back({llinf,0});
  sort(imos.begin(),imos.end());
  int is=imos.size();
  long long ic=0,res=0;
  for(int i=0;i<is-1;i++){
    ic+=imos[i].second;
    if(imos[i].first==imos[i+1].first){continue;}
    res=max(ic*(bo+in*(imos[i+1].first-1)),res);
  }
  cout << res << '\n';
  return 0;
}