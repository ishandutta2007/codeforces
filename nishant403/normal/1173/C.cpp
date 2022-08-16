#include <bits/stdc++.h> 

using namespace std; 
#define int long long 
#define pb push_back 
#define S second 
#define F first 
#define f(i,n) for(int i=0;i<n;i++) 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 

vector<bool> cur(200005,0); 

bool check(int b[],int n,int step)

 { vector<bool> ff(n+1,0);

 
  for(int i=0;i<step;i++) ff[b[i]] = 1; 
  for(int i=1;i<=n;i++) if(cur[i]) ff[i] = 1; 
  
  int myval = n+1; 
  
  for(int i=1;i<=n;i++) 
  if(ff[i] == 0 ) { myval = i; break; }
  
   if(myval == n+1 ) return true; 
   
   int k = myval; 
   
   for(int i = step; i< min(step+k-1,n) ; i++)
      ff[b[i]] = 1; 
      
   
   
      
      
      for(int i=k;i<=n;i++)
      
       { 
       	
       	if(ff[i] == 0 ) return false; 
       ff[b[min(step+i,n)-1]] = 1; 
       
       }
       
        return true; 
        
} 


signed main()
{
	
	 fast;
	  int n; 
	  cin >> n; 
	  
	  int b[n],x; 
	  
	  f(i,n) { cin>> x; cur[x] = 1;} 
	  
	  
	 f(i,n) cin >> b[i]; 
	 
	 int l = 0, r = n;
	  int ans = n; 
	 
	 
	 while(l<=r)
	 
	  { int mid= (l+r)/2; 
	  
	  if(check(b,n,mid)) 
	     { ans = min(ans,mid); r = mid-1; }
	 
	  else l = mid+1; } 
	 
	  
	  
	  int ready = b[n-1];
	  
	  
	  for(int i = n-1; i > (n-1)-ready ; i-- ) 
	  
	 { if(b[i] != (b[n-1] - (n-1-i)) ) ready = 0; } 
	 
	 if(ready == 0 ) { cout << ans+n; return 0; }
	 
	 
	  for(int i=1;i<=ready;i++) cur[i] = 1;
	   for(int i = ready+1 ; i<=n;i++) 
	   
	   { if(cur[i] == 0 ) { cout << ans+n; return 0; }
	    cur[b[i-(ready+1)]] = 1; } 
	    
	    cout << n-ready;
	    
}