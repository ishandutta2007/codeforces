#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

vector<pi> g;
vector<int> id;
int n;
string s,t;

void dfs1(int v){
  if(g[v].first>=0){dfs1(g[v].first);}
  id[v]=t.size();
  t.push_back(s[v]);
  if(g[v].second>=0){dfs1(g[v].second);}
}

int k;
vector<bool> fl;
set<int> cand,doub;
void dfs2(int v){
  cand.insert(id[v]);

  if(g[v].first>=0){dfs2(g[v].first);}

  if(doub.find(id[v])!=doub.end()){
    if(g[v].second>=0){dfs2(g[v].second);}
  }
  else if(fl[id[v]]){
    if(cand.size()+doub.size()<=k){
      for(auto &nx : cand){doub.insert(nx);}
      cand.clear();
      if(g[v].second>=0){dfs2(g[v].second);}
    }
  }

  if(cand.find(id[v])!=cand.end()){cand.erase(id[v]);}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> s;
  g.resize(n);
  id.resize(n);
  for(int i=0;i<n;i++){
    cin >> g[i].first >> g[i].second;
    g[i].first--;
    g[i].second--;
  }
  dfs1(0);
  fl.resize(n);
  fl[n-1]=false;
  for(int i=n-2;i>=0;i--){
    if(t[i]==t[i+1]){fl[i]=fl[i+1];}
    if(t[i]<t[i+1]){fl[i]=true;}
    if(t[i]>t[i+1]){fl[i]=false;}
  }
  dfs2(0);
  vector<bool> dv(n,false);
  for(auto &nx : doub){dv[nx]=true;}
  for(int i=0;i<n;i++){
    cout << t[i];
    if(dv[i]){cout << t[i];}
  }cout << '\n';
  return 0;
}