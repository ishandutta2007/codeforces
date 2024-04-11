#include<bits/stdc++.h>

using namespace std;

typedef struct{
  long long a,b,c,d,h;
}ladder;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,k;
    cin >> n >> m >> k;
    vector<map<long long,long long>> dp(n);
    //vector<vector<long long>> dp(n,vector<long long>(m,1e18));
    vector<long long> x(n);
    for(auto &nx : x){cin >> nx;}
    vector<vector<ladder>> ld(n);
    for(int i=0;i<k;i++){
      ladder l;
      cin >> l.a >> l.b >> l.c >> l.d >> l.h;
      l.a--;l.b--;l.c--;l.d--;
      dp[l.a][l.b]=1e18;
      dp[l.c][l.d]=1e18;
      ld[l.c].push_back(l);
    }
    dp[0][0]=0;
    dp[n-1][m-1]=1e18;
    for(int i=0;i<n;i++){
      for(auto &nx : ld[i]){dp[nx.c][nx.d]=min(dp[nx.c][nx.d],dp[nx.a][nx.b]-nx.h);}
      if(dp[i].size()>=2){
        long long pj=-1,pc=-1;
        vector<long long> mem;
        for(auto &nx : dp[i]){
          mem.push_back(nx.first);
          if(pj==-1){pj=nx.first;pc=nx.second;}
          else{
            pc+=(nx.first-pj)*x[i];
            pc=min(pc,nx.second);
            pj=nx.first;
            nx.second=pc;
          }
        }
        reverse(mem.begin(),mem.end());
        pj=-1;pc=-1;
        for(auto &nx : mem){
          if(pj==-1){pj=nx;pc=dp[i][nx];}
          else{
            pc+=(pj-nx)*x[i];
            pc=min(pc,dp[i][nx]);
            pj=nx;
            dp[i][nx]=pc;
          }
        }
      }
    }
    if(dp[n-1][m-1]>(5e17)){cout << "NO ESCAPE\n";}
    else{cout << dp[n-1][m-1] << '\n';}
  }
  return 0;
}