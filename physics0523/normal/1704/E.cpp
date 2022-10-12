#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
using Graph=vector<vector<int>>;

long long spmod(long long x){
  if(x>=mod){
    return mod+(x%mod);
  }
  else{return x;}
}

long long add(long long a,long long b){
  return spmod(a+b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    Graph g(n);
    Graph rev(n);
    for(int i=0;i<m;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      rev[v].push_back(u);
    }
    int end;
    vector<int> bk(n);
    for(int i=0;i<n;i++){
      if(g[i].size()==0){end=i;}
      bk[i]=g[i].size();
    }
    vector<vector<long long>> dp(n+5,vector<long long>(n+5,0));
    dp[end][0]=1;
    queue<int> q;
    q.push(end);
    while(!q.empty()){
      int od=q.front();q.pop();
      for(auto &nx : rev[od]){
        for(int i=0;i<=n;i++){
          dp[nx][i+1]=add(dp[nx][i+1],dp[od][i]);
        }
        // cerr << nx << ' ' << bk[nx] << '\n';
        bk[nx]--;
        if(bk[nx]==0){q.push(nx);}
      }
    }

    vector<long long> ra(n+5,0);
    for(int i=0;i<n;i++){
      for(int j=0;j<=n;j++){
        // cerr << dp[i][j] << " ";
        ra[j]=add(ra[j],spmod(a[i]*dp[i][j]));
      }// cerr << "\n";
    }
    // for(int i=0;i<=n;i++){
    //   cerr << ra[i] << " ";
    // }cerr << "\n";

    long long res=0,cur=0;
    for(int i=0;i<=n;i++){
      cur+=ra[i];
      if(cur>0){
        res=(i+1);
        cur--;
      }
    }
    if(cur>0){
      res=(n+1+cur)%mod;
    }
    cout << res%mod << "\n";
  }
  return 0;
}