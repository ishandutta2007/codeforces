#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
const int N = 2e5+10;
 
int safe[N],n,m,k,q,ma=0,dp[4][2],first[N],last[N];
pii pos[4][2],x;
 
int dis(pii a,pii b)
{
 return abs(a.F-b.F) + abs(a.S-b.S);   
}
 
void getnear(int b,pii & c)
{   
    if(safe[q-1] <= b) {c.F = c.S = safe[q-1];  return ; }
    if(safe[0] >= b) { c.F = c.S = safe[0]; return; }
    
 int ub =*(lower_bound(safe,safe+q,b)-1);   
 int lb =*(lower_bound(safe,safe+q,b)); 
       
    c.F = ub;
    c.S = lb;
    return; 
}
 
void solve()
{ 
 
  scanf("%lld %lld %lld %lld",&n,&m,&k,&q);
    
  f(i,n+1) last[i] = -1,first[i] = 1e7;  
    
  f(i,k) 
  {  
     scanf("%lld %lld",&x.F,&x.S);
      
     last[x.F] = max(last[x.F],x.S);
     first[x.F] = min(first[x.F],x.S);
     ma=max(ma,x.F);
  }
 
  f(i,q) scanf("%lld",&safe[i]);
    
  sort(safe,safe+q);  
  
  if(first[1] == 1e7)
  {
      getnear(1,x);
      pos[0][1] = pos[1][1] = {1,x.F};
      pos[2][1] = pos[3][1] = {1,x.S};
      f(i,4) dp[i][1] = abs(1-pos[i][1].S);
  } 
  else 
  {
      getnear(last[1],x);
      pos[0][1] = pos[1][1] = {1,x.F};
      pos[2][1] = pos[3][1] = {1,x.S};
      
      if(ma==1) f(i,4) pos[i][1].S = last[i];
      
      f(i,4)  dp[i][1] = abs(pos[i][1].S-last[1]) + abs(last[1]-1) ;
  }  
   
  for(int i=2;i<=ma;i++)  
  {   
    if(first[i] == 1e7)
  { 
    f(j,4) pos[j][i&1] = pos[j][(i&1)^1];
    f(j,4) pos[j][i&1].F++;
    f(j,4) dp[j][i&1]=dp[j][(i&1)^1]+1;    
  }
  else 
  {
      getnear(first[i],x);
      pos[0][i&1] = {i,x.F};
      pos[1][i&1] = {i,x.S};
      
      if(i==ma)  pos[0][i&1].S = pos[1][i&1].S = first[i];   
      
      getnear(last[i],x);
      pos[2][i&1] = {i,x.F};
      pos[3][i&1] = {i,x.S};
      
      if(i==ma)  pos[2][i&1].S = pos[3][i&1].S = last[i];   
      
      f(j,4) dp[j][i&1] = 1e13;
      
      f(j,4)
          f(k,4) 
      {
          int cost1 = 1+dp[k][(i&1)^1];
          int cost2 = 1+dp[k][(i&1)^1];
          
          cost1+=abs(pos[k][(i&1)^1].S-first[i]);
          cost1+=abs(first[i]-last[i]);
          cost1+=abs(last[i]-pos[j][i&1].S);
          
          cost2+=abs(pos[k][(i&1)^1].S-last[i]);
          cost2+=abs(first[i]-last[i]);
          cost2+=abs(first[i]-pos[j][i&1].S);
          
          dp[j][i&1] = min(dp[j][i&1],min(cost1,cost2));         
      }
        
  }
      
  }
    
  int ans = (int)1e15;
    
  f(i,4) ans = min(ans,dp[i][ma&1]);
    
  printf("%lld",ans);
}
 
signed main()
{
    solve();
}