#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[100009];

int main(){
  int n,q;
  scanf("%i %i",&n,&q);
  ll val[n];
  int col[n];
  for(int i = 0;i<n;i++)  
    scanf("%lld",&val[i]);
  for(int i = 0;i<n;i++)
    scanf("%i",&col[i]);
  ll l,r;
  ll u1,u2;
  int i1,i2;
  ll cur;
  while(q--){
    scanf("%lld %lld",&l,&r);
    u1 = 0,u2 = 0,i1 = -1,i2 = -1;
    for(int i = 1;i<=n;i++)  
      dp[i] = (ll)-1<<55;
    for(int j = 0;j<n;j++){
      cur = (ll)-1<<55;
      cur = max(cur,dp[col[j]]+l*val[j]);
      if(col[j]!=i1)cur=max(cur,u1+r*val[j]);
      if(col[j]!=i2)cur=max(cur,u2+r*val[j]);
      dp[col[j]] = max(dp[col[j]],cur);
      if(cur>=u1){
        if(i1!=col[j])u2=u1,i2=i1; 
        u1=cur,i1=col[j];
      }
      else if(col[j]!=i1 && cur >= u2)
        u2 = cur,i2 = col[j];
    }
    printf("%lld\n",u1);
  }
  return 0;
}