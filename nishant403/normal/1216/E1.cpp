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

int po(int x)
{
 return(x*(x+1))/2;   
}
//returns the total digits for x complete sequences
int go(int x)
{
 int res = 0;  
 int temp = 9;   
 int mul = 1;   
    
 while(x>0)
 {
 res+=mul*po(min(temp,x));    
 res+=mul*max(x-temp,(int)0)*temp;
    
 x-=min(temp,x);   
 mul++;
 temp*=10;    
 }
    
 return res;   
}

int get(int x)
{
 int res = 0;  
 int temp = 9;   
 int mul = 1;   
    
 while(x>0)
 {
 res+=mul*(min(temp,x));    
 x-=min(temp,x);   
 mul++;
 temp*=10;    
 }
    
 return res;       
}

void solve()
{
  int n;
  cin>> n;
 
    
  int l=0,r=7e8,ans=0;
    
  while(l<=r)
  {
   int mid =(l+r)/2;  
   if(go(mid) < n) ans=max(ans,mid),l=mid+1;
   else r=mid-1;
  }
    
 
  int at = ans+1;
  int rem = n-go(ans);
    
  l =0;
  r = at;
  ans=0;
   
  while(l<=r)
  {
   int mid =(l+r)/2;
   if(get(mid) < rem)
   {
    ans=max(ans,mid); l=mid+1;   
   }
   else r=mid-1;   
  }
     
  int final = ans+1;
  int hhhh = rem - get(ans);  
    
  vi j;
    
  while(final)
  {
   j.pb(final%10);
   final/=10;
  }
    
  reverse(j.begin(),j.end());
  
  cout<<j[hhhh-1] << '\n';
  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}