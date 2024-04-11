#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> dist(1024,1e9);
  dist[0]=0;
  dist[1]=0;
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    int od=q.front();q.pop();
    for(int i=1;i<=od;i++){
      int nx=od+(od/i);
      if(nx>=1024){continue;}
      if(dist[nx]>1e8){
        dist[nx]=dist[od]+1;
        q.push(nx);
      }
    }
  }
  // int md=0;
  // for(auto &nx : dist){
  //   md=max(md,nx);
  // }
  // cout << md << '\n';]
  // then, md=12

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    k=min(15*n,k);
    vector<int> dp(k+1,0);
    vector<int> b(n);
    for(auto &nx : b){cin >> nx;}
    vector<int> c(n);
    for(auto &nx : c){cin >> nx;}

    for(int i=0;i<n;i++){
      int v=dist[b[i]],w=c[i];
      for(int j=k-v;j>=0;j--){
        dp[j+v]=max(dp[j+v],dp[j]+w);
      }
    }
    cout << dp[k] << '\n';
  }
  return 0;
}