#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int f(vector<int> &a){
  int res=0,c=0;
  for(auto &nx : a){
    if(nx){c=0;}
    else{c++;}
    res+=max(c-1,0);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<int>> mem(4444);
  vector<vector<vector<pi>>> bk(n,vector<vector<pi>>(m));
  int lin=0;
  for(int i=0;i<m;i++){
    int x=0,y=i,s=0,id=0;
    while(x<n && y<m){
      mem[lin].push_back(0);
      bk[x][y].push_back({lin,id});
      if(s){x++;}else{y++;}
      s=1-s;
      id++;
    }
    lin++;
  }
  for(int i=0;i<n;i++){
    int x=i,y=0,s=1,id=0;
    while(x<n && y<m){
      mem[lin].push_back(0);
      bk[x][y].push_back({lin,id});
      if(s){x++;}else{y++;}
      s=1-s;
      id++;
    }
    lin++;
  }
  vector<vector<int>> cur(n,vector<int>(m,0));
  long long res=n*m;
  for(auto &nx : mem){res+=f(nx);}
  while(q>0){
    q--;
    int x,y;
    cin >> x >> y;
    x--;y--;
    int tg=1-cur[x][y];
    cur[x][y]=tg;
    if(tg==1){res--;}else{res++;}
    for(auto &nx : bk[x][y]){
      res-=f(mem[nx.first]);
      mem[nx.first][nx.second]=tg;
      res+=f(mem[nx.first]);
    }
    cout << res << '\n';
  }
  return 0;
}