#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

typedef struct{
  int i,j,col;
}paint;

vector<vector<int>> c;
vector<vector<bool>> alr;
int dx4[4]={0,0,1,1};
int dy4[4]={0,1,0,1};
bool jud(int i,int j){
  int tg=-1;
  for(int k=0;k<4;k++){
    int cc=c[i+dx4[k]][j+dy4[k]];
    if(cc!=-1){
      if(tg==-1){tg=cc;}
      else if(tg!=cc){return false;}
    }
  }
  if(tg==-1){return false;}
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  c.resize(n);
  alr.resize(n);
  for(int i=0;i<n;i++){
    c[i].resize(m);
    alr[i].resize(m);
    for(int j=0;j<m;j++){
      cin >> c[i][j];
      alr[i][j]=false;
    }
  }
  queue<pi> q;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m-1;j++){
      if(jud(i,j)){
        q.push({i,j});
        alr[i][j]=true;
      }
    }
  }
  vector<paint> res;
  while(!q.empty()){
    pi od=q.front();q.pop();
    int i=od.first,j=od.second;
    if(jud(i,j)){res.push_back({i,j,max({c[i][j],c[i][j+1],c[i+1][j],c[i+1][j+1]})});}
    c[i][j]=-1;c[i][j+1]=-1;c[i+1][j]=-1;c[i+1][j+1]=-1;
    for(int di=-1;di<=1;di++){
      for(int dj=-1;dj<=1;dj++){
        int ni=i+di,nj=j+dj;
        if(!(0<=ni&&ni<n-1)){continue;}
        if(!(0<=nj&&nj<m-1)){continue;}
        if(jud(ni,nj) && !alr[ni][nj]){
          q.push({ni,nj});
          alr[ni][nj]=true;
        }
      }
    }
  }

  for(auto &nx : c){
    for(auto &ny : nx){
      if(ny!=-1){cout << "-1\n";return 0;}
    }
  }
  reverse(res.begin(),res.end());
  cout << res.size() << '\n';
  for(auto &nx : res){
    cout << nx.i+1 << ' ' << nx.j+1 << ' ' << nx.col << '\n';
  }
  return 0;
}