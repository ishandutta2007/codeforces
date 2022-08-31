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
  string s,t;
  cin >> s >> t;
    
  int n = s.length();
  int maxcover[n];
    
  int l = 0,r = 0;
    
  f(i,n)
  {
      if(r==t.length())
      {
          for(;i<n;i++) maxcover[i] = maxcover[i-1];
          break;
      }
      
      maxcover[i] = (s[i]==t[r]);   
     
      if(s[i] == t[r]) r++;
      
      if(i) maxcover[i]+=maxcover[i-1];
  }
   
  int prevcover[n];
    
   r = ((int)t.length() - 1);  
   
  f(i,n)
  {
    if(r==-1) 
    {
     for(;i<n;i++) prevcover[n-i-1] = prevcover[n-i];    
    }
      
    if(s[n-i-1] == t[r])  
    {
      prevcover[n-i-1] = 1;
      if(i!=0) prevcover[n-i-1]+=prevcover[n-i]; 
      r--;  
    }
    else
    {
     prevcover[n-i-1] = 0;   
     if(i!=0)  prevcover[n-i-1]+=prevcover[n-i];  
    }
        
  }
    
  int ans = 0;
    
  f(i,n) if(maxcover[i] == (int)t.length())
  {
   ans=max(ans,n-(i+1)); break;   
  }
    
  for(int i=0;i<n;i++)
  {
      
   //from i to n is nextdone   
    int nextdone = prevcover[i];   
    int rem = (int)t.length()-nextdone;    
      
    //find min index from 0 to i-1  whose value is atleast rem
   int l = 0,r = i-1,fin = 1e7;
       
    while(l<=r)
    {
        int mid =(l+r)/2;
        
        if(maxcover[mid] >= rem)
        {
          r= mid -1;
          fin=min(fin,mid);  
        }
        else l = mid + 1;    
    }
      
   if(fin != 1e7)  
   {
   ans=max(ans,i-fin-1);   
   }
      
  }
    
    f(i,n) if(maxcover[i] == (int)t.length())
         ans = max(ans,n-(i+1));
    
    f(i,n) if(prevcover[i] == (int)t.length())
         ans = max(ans,i);
        
    cout << ans;
    
    
    
}
 
signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}