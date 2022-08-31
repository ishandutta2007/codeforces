#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(i=0;i<n;i++)


bool check(vector<int> a,int n,int m,int k)
{
    
 if( a[0] + k > m ) a[0] = 0;    
  
 for(int i=1;i<n;i++)   
 { 
  if(a[i] < a[i-1] )
  {
      if( k >= a[i-1] - a[i]) a[i] = a[i-1];
      else return false;
  }
     
  else
  {
   if( ( m-a[i] + a[i-1]) <= k)     
      a[i] = a[i-1];
  }
            
 }
   
    return true;
}

signed main()
{
    fast;
    int i,j,k,n,m;
    cin >> n >> m;
        
    vector<int> a(n);
    
    f(i,n) cin >> a[i];
    
   int ans = m; 
   
    
    int l =0;
    int r =m;
    
    while(l<=r)
    {
     int mid = (l+r)/2;
        
        if(check(a,n,m,mid)) { ans=min(ans,mid); r = mid-1; }   
        else l = mid+1;
    }
    
   
    cout << ans;
}