#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(i=0;i<n;i++)

signed main()
{
 fast;
 int n,i;
    
    cin >> n;
    
 int a[n+1],rev[n+1];   
 vector<pair<int,int> > ans;   
    
    f(i,n) { cin >> a[i+1]; rev[a[i+1]] = i+1; }
      
    
    for(i=1;i<n;i++)
    {
     if(a[i] == i) continue;   
        
     int need = rev[i];   
      
      if ( abs(need - i)*2 >= n ) 
      {
       swap(a[i],a[need]);
        rev[i] = i;
        rev[a[need]] = need;
          
          ans.pb({i,need});  
      }
        
     else if(2*abs(i-1) >=n && 2*abs(need-1) >= n)
     {
       swap(a[need],a[1]);
        rev[a[need]] = need;
        rev[a[1]] = 1;
         
         ans.pb({need,1});  
        
       swap(a[i],a[1]);
         rev[a[i]] = i;
        rev[a[1]] = 1;
         
         ans.pb({i,1});  
       
            swap(a[need],a[1]);
        rev[a[need]] = need;
        rev[a[1]] = 1;
         
         ans.pb({need,1});   
         
     }
        
      else if(2*abs(i-n) >=n && 2*abs(need-n) >= n)
     {
       swap(a[need],a[n]);
        rev[a[need]] = need;
        rev[a[n]] = n;
         
         ans.pb({need,n});  
        
       swap(a[i],a[n]);
         rev[a[i]] = i;
        rev[a[n]] = n;
         
         ans.pb({i,n});  
          
      swap(a[need],a[n]);
        rev[a[need]] = need;
        rev[a[n]] = n;
         
         ans.pb({need,n});  
                
     }  
        
           
       else
       {
             swap(a[need],a[1]);
        rev[a[need]] = need;
        rev[a[1]] = 1;
         
         ans.pb({need,1});  
     
        swap(a[n],a[1]);
         rev[a[n]]=n;
          rev[a[1]]=1;
          
          ans.pb({1,n});
              
               swap(a[i],a[n]);
         rev[a[i]] = i;
        rev[a[n]] = n;
         
         ans.pb({i,n});  
   
        
        swap(a[n],a[1]);
         rev[a[n]]=n;
          rev[a[1]]=1;
          
          ans.pb({1,n});
          
                     swap(a[need],a[1]);
        rev[a[need]] = need;
        rev[a[1]] = 1;
         
         ans.pb({need,1});  
      
       }
        
            
        
    }
    
    cout << ans.size() << "\n";
    
    for(auto x : ans) cout << x.F << " " << x.S << "\n";
}