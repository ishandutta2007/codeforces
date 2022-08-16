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


void solve()
{
  int n,q,x;
  cin >> n>> q;
  
  int a;
  int h = -1,id = -1;  
    
  deque<int> dq;     
      
  f(i,n) 
  { cin >> a;
     
   if(a>h)
     {
       h=a;
       id=i;  
     }
   dq.pb(a);
  }
    
  vector<pii> store(id);
  
  for(int i=0;i<id;i++)
  {
      
      store[i].F = dq.front();
      dq.pop_front();
      
      store[i].S = dq.front();
      dq.pop_front();
      
      if(store[i].F > store[i].S)
      {
       dq.push_front(store[i].F);
       dq.pb(store[i].S);   
      }
      else
      {
       dq.push_front(store[i].S);
       dq.pb(store[i].F);   
      }
  } 
   
 vector<pii> dp2(n-1);
    
 for(int i=0;i<n-1;i++)
 {
      dp2[i].F = dq.front();
      dq.pop_front();
      
      dp2[i].S = dq.front();
      dq.pop_front();
      
      if(dp2[i].F > dp2[i].S)
      {
       dq.push_front(dp2[i].F);
       dq.pb(dp2[i].S);   
      }
      else
      {
       dq.push_front(dp2[i].S);
       dq.pb(dp2[i].F);   
      }
 }
    
  while(q--)
  {
     cin >> x; 
     
    if(x<=id)
    {
     x--;
     cout << store[x].F <<" " << store[x].S << "\n";
    }
      
    else
    {
       x=x-id;
       x--;
       x=x%(n-1);
        
       cout << dp2[x].F << " " << dp2[x].S << "\n"; 
    }
      
  }
    
}

signed main()
{
    fast;
    solve();
}