#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = (int)1e5 + 9;
ll dp[N];
struct ring{
  int inner,outer,hi;
};

bool comp(ring a,ring b){
  return (a.outer>b.outer);
}

int main(){
  int n;
  cin >> n;
  ring cur[n];
  for(int i = 0;i<n;i++){
    cin >> cur[i].inner >> cur[i].outer >> cur[i].hi;
  }
  sort(cur,cur+n,comp);
  for(int i = n-2;i>=0;i--){
    if(cur[i].outer==cur[i+1].outer){
      cur[i].hi+=cur[i+1].hi;
      cur[i+1].hi=0;
      cur[i].inner=min(cur[i].inner,cur[i+1].inner);
    }
  }
  stack<int>ix;
  ll ans = 0;
  for(int i = 0;i<n;i++){
     if(cur[i].hi==0)continue;
     while(!ix.empty() and cur[ix.top()].inner>=cur[i].outer)ix.pop();
     dp[i]=cur[i].hi;
     if(!ix.empty())
       dp[i]+=dp[ix.top()];
     ans=max(dp[i],ans);
     ix.push(i);
  }
  cout << ans << "\n";
  return 0;
}