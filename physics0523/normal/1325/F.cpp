#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int ceil_sqn;
int param;

vector<int> col,par;
bool kill;

void dfs(int v,int pv,int d,Graph &g){
  if(kill){return;}

  col[v]=d;
  par[v]=pv;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    if(col[nx]==d){
      // cycle detected
      cout << 2 << "\n";
      vector<int> res={v};
      while(res.back()!=nx){
        res.push_back(par[res.back()]);
      }
      cout << res.size() << "\n";
      for(int i=0;i<res.size();i++){
        if(i){cout << " ";}
        cout << res[i];
      }cout << "\n";
      kill=true;
      break;
    }
  }
  if(kill){return;}

  for(auto &nx : g[v]){
    if(col[nx]==-1){
      dfs(nx,v,(d+1)%param,g);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;
  col.resize(n+1);
  par.resize(n+1);

  for(int i=1;i<=n;i++){col[i]=-1;}

  for(ceil_sqn=1;;ceil_sqn++){
    if(ceil_sqn*ceil_sqn>=n){break;}
  }
  param=ceil_sqn-1;

  Graph g(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  kill=false;
  dfs(1,-1,0,g);

  if(!kill){
    vector<int> bk(param,0);
    for(int i=1;i<=n;i++){
      bk[col[i]]++;
    }
    int tg=0;
    for(int i=0;i<param;i++){
      if(bk[tg]<bk[i]){tg=i;}
    }
    int cnt=0;
    cout << "1\n";
    for(int i=1;i<=n && cnt<ceil_sqn;i++){
      if(col[i]==tg){
        if(cnt){cout << " ";}
        cout << i;
        cnt++;
      }
    }cout << "\n";
  }
  return 0;
}