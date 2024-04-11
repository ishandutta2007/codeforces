#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  long long k;
  cin >> n >> m >> k;
  k--;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}

  vector<int> u(m),v(m);
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i];
    u[i]--;v[i]--;
  }

  if(k==0){
    int res=inf;
    for(auto &nx : a){
      res=min(res,nx);
    }
    cout << res << '\n';
    return 0;
  }

  int st=0,fi=inf;
  while(st<=fi){
    int te=(st+fi)/2;
    Graph eg(n);
    vector<int> bk(n,0);
    for(int i=0;i<m;i++){
      if(a[u[i]]<=te && a[v[i]]<=te){
        eg[v[i]].push_back(u[i]);
        bk[u[i]]++;
      }
    }
    queue<int> q;
    vector<long long> dp(n,0);
    for(int i=0;i<n;i++){
      if(bk[i]==0){
        q.push(i);
      }
    }

    while(!q.empty()){
      int od=q.front();q.pop();
      for(auto &nx : eg[od]){
        dp[nx]=max(dp[nx],dp[od]+1);
        bk[nx]--;
        if(bk[nx]==0){q.push(nx);}
      }
    }

    // cerr << te << ':';
    // for(auto &nx : dp){
    //   cerr << nx << ' ';
    // }cerr << '\n';

    long long lg=0;
    for(auto &nx : dp){lg=max(lg,nx);}
    for(auto &nx : bk){
      if(nx>0){lg=8e18;}
    }
    if(lg>=k){fi=te-1;}else{st=te+1;}
  }

  int res=st;
  if(res>1000000000){res=-1;}
  cout << res << '\n';
  return 0;
}