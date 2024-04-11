#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define inf 1072114514
#define llinf 4154118101919364364

using namespace std;

int n,m;

void bfs(int sv,vector<int> &res,vector<long long> &a){
  queue<int> vq;
  vq.push(sv);
  res[sv]=0;
  while(!vq.empty()){
    int od=vq.front();vq.pop();
    if(od%m!=0 && res[od-1]==inf && a[od-1]!=-1){
      res[od-1]=res[od]+1;
      vq.push(od-1);
    }
    if(od%m!=(m-1) && res[od+1]==inf && a[od+1]!=-1){
      res[od+1]=res[od]+1;
      vq.push(od+1);
    }
    if((od-m)>=0 && res[od-m]==inf && a[od-m]!=-1){
      res[od-m]=res[od]+1;
      vq.push(od-m);
    }
    if((od+m)<n*m && res[od+m]==inf && a[od+m]!=-1){
      res[od+m]=res[od]+1;
      vq.push(od+m);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long w;
  cin >> n >> m >> w;
  vector<long long> a(n*m);
  for(int i=0;i<n*m;i++){cin >> a[i];}
  vector<int> sr(n*m,inf),gr(n*m,inf);
  bfs(0,sr,a);
  bfs(n*m-1,gr,a);
  long long res;
  if(sr[n*m-1]!=inf){res=w*sr[n*m-1];}
  else{res=llinf;}
  long long sp=llinf,fp=llinf;
  for(int i=0;i<n*m;i++){
    if(sr[i]!=inf && a[i]>0){
      sp=min(sp,w*sr[i]+a[i]);
    }
  }
  for(int i=0;i<n*m;i++){
    if(gr[i]!=inf && a[i]>0){
      fp=min(fp,w*gr[i]+a[i]);
    }
  }
  res=min(sp+fp,res);
  if(res==llinf){res=-1;}
  cout << res << "\n";
  return 0;
}