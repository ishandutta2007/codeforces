#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> dp(n+1,1);
    vector<int> mem(n+1,0);
    Graph g(n+1);
    for(int i=0;i<n;i++){
      int p,q;
      cin >> p >> q;
      g[p].push_back(q);
      g[q].push_back(p);
      mem[p]++;mem[q]++;
    }
    queue<int> que;
    for(int i=1;i<=n;i++){
      if(mem[i]==1){que.push(i);}
    }
    while(!que.empty()){
      int v=que.front();
      que.pop();
      for(auto &nx : g[v]){
        mem[nx]--;
        if(mem[nx]==1){que.push(nx);}
        dp[nx]+=dp[v];
      }
    }
    long long res=((long long)n);
    res*=((long long)n);
    res-=((long long)n);
    for(int i=1;i<=n;i++){
      if(mem[i]==2){
        res-=llnCr(dp[i],2);
      }
    }
    cout << res << "\n";
  }
  return 0;
}