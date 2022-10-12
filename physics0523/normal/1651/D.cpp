#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using ppp=pair<pi,pi>;

pi na={-1e8,-1e8};
int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<pi,int> mp;
  vector<int> x(n+1),y(n+1);
  for(int i=1;i<=n;i++){
    cin >> x[i] >> y[i];
    mp[{x[i],y[i]}]=i;
  }
  vector<pi> res(n+1,na);
  queue<ppp> q;
  for(int i=1;i<=n;i++){
    for(int k=0;k<4;k++){
      int nx=x[i]+dx4[k];
      int ny=y[i]+dy4[k];
      if(mp[{nx,ny}]==0){
        res[i]={nx,ny};
        q.push({{x[i],y[i]},{nx,ny}});
        break;
      }
    }
  }
  while(!q.empty()){
    ppp od=q.front();q.pop();
    int cx=od.first.first;
    int cy=od.first.second;
    pi cp=od.second;
    for(int k=0;k<4;k++){
      int nx=cx+dx4[k];
      int ny=cy+dy4[k];
      int id=mp[{nx,ny}];
      if(id>0 && res[id]==na){
        res[id]=cp;
        q.push({{nx,ny},cp});
      }
    }
  }
  for(int i=1;i<=n;i++){
    cout << res[i].first << ' ';
    cout << res[i].second << '\n';
  }
  return 0;
}