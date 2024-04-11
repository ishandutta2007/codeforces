#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  Graph g(n+m+k+1);
  map<pi,int> mp;
  for(int i=0;i<=k;i++){
    int x,y;
    if(i!=k){cin >> x >> y;}
    else{x=n;y=m;}
    x--;y--;

    for(int d=-1;d<=1;d++){
      if(d!=0 && i==k){continue;}
      if((x+d)<0 || (x+d)>=n){continue;}
      g[n+m+i].push_back({1,x+d});
      g[x+d].push_back({0,n+m+i});
    }
    for(int d=-1;d<=1;d++){
      if(d!=0 && i==k){continue;}
      if((y+d)<0 || (y+d)>=m){continue;}
      g[n+m+i].push_back({1,n+y+d});
      g[n+y+d].push_back({0,n+m+i});
    }
    if(i!=k){
      for(int t=0;t<4;t++){
        if(mp[{x+dx4[t],y+dy4[t]}]!=0){
          int id=mp[{x+dx4[t],y+dy4[t]}];
          g[id].push_back({0,n+m+i});
          g[n+m+i].push_back({0,id});
        }
      }
    }
    else{
      if(mp[{x,y}]!=0){
        int id=mp[{x,y}];
        g[id].push_back({0,n+m+i});
        g[n+m+i].push_back({0,id});
      }
    }
    mp[{x,y}]=n+m+i;
  }

  // for(int i=0;i<=n+m+k;i++){
  //   for(auto &nx : g[i]){
  //     cout << i << ' ' << nx.second << ' ' << nx.first << '\n';
  //   }
  // }

  k++;
  vector<int> dist(n+m+k,inf);
  vector<bool> fl(n+m+k,false);
  deque<int> dq;
  dist[n+m]=0;
  dq.push_front(n+m);
  while(!dq.empty()){
    int od=dq.front();dq.pop_front();
    if(fl[od]){continue;}
    //cout << od << ' ' << dist[od] << '\n';
    fl[od]=true;
    for(auto &nx : g[od]){
      int nv=nx.second;
      if(dist[od]+nx.first<dist[nv]){
        dist[nv]=dist[od]+nx.first;
        if(nx.first==0){dq.push_front(nv);}
        else{dq.push_back(nv);}
      }
    }
  }

  if(dist[n+m+k-1]==inf){dist[n+m+k-1]=-1;}
  cout << dist[n+m+k-1] << '\n';
  return 0;
}