#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> res(m+1,-1);
  res[0]=0;
  for(int i=1;i<=n;i++){
    int typ,y;
    long long x;
    cin >> typ >> x >> y;
    vector<int> dist(m+1,1e9);
    for(int j=0;j<=m;j++){
      if(res[j]!=-1){dist[j]=0;}
      long long tg=j;
      if(typ==1){
        tg*=100000;
        tg+=x;
        tg=llceil(tg,100000);
      }
      else{
        tg*=x;
        tg=llceil(tg,100000);
      }
      if(tg<=m){dist[tg]=min(dist[tg],dist[j]+1);}
    }
    for(int j=0;j<=m;j++){
      if(dist[j]<=y && res[j]==-1){
        res[j]=i;
      }
    }
  }
  for(int i=1;i<=m;i++){
    if(i-1){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}