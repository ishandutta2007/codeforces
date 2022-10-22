#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;
int INF = 100000000;
int p[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

int gcd(int a, int b) {
  if(a<b)swap(a,b);
  return b?gcd(b,a%b):a;
}

int to_b(int n) {
  int b = 0;
  REP(i,17) if(n%p[i]==0) b = b | (1 << i);
  return b;
}

int main()
{
  int n;
  cin>>n;
  vecint a(n);
  REP(i,n)cin>>a[i];
  vector<tuple<int,int>> v;
  REP(i,n){
    v.emplace_back(a[i],i);
  }
  sort(begin(v),end(v));
  vecint bt(60);
  REP(i,60)bt[i]=to_b(i);
  vector<vecint> dp(n+1,vecint(1<<17,INF));
  vector<vecint> sk(n+1,vecint(1<<17,INF));
  vector<vecint> tb(1<<17);
  REP(i,1<<17) {
    REP(j,60) {
      if(!j) continue;
      int kb = bt[j];
      if(i&kb) continue;
      tb[i].push_back(j);
    }
  }
  dp[0][0] = 0;
  REP(i,n) {
    REP(j,1<<17) dp[i+1][j] = dp[i][j] + a[i] - 1;
    REP(j,1<<17) sk[i+1][j] = 1;
    REP(j,1<<17) {
      for(int k:tb[j]) {
        int kb = bt[k];
        if (dp[i+1][j|kb] > dp[i][j] + abs(a[i]-k)) {
          dp[i+1][j|kb] = dp[i][j] + abs(a[i]-k);
          sk[i+1][j|kb] = k;
        }
      }
    }
  }
  vecint res;
  auto itr = min_element(begin(dp[n]),end(dp[n]));
  int ind = itr-begin(dp[n]);
  REP(i,n) {
    int j = n-i;
    res.push_back(sk[j][ind]);
    ind = ind ^ bt[sk[j][ind]];
  }
  reverse(begin(res),end(res));
  REP(i,n){
    if(i)cout<<' ';
    cout<<res[i];
  }
  cout<<endl;
  return 0;
}