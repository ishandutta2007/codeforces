#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
int main()
{
  
 fast;   
 ll n,i,j,k,l,ans=0,temp,sum;
    
 cin >> n;
    
 ll a[n];
 ll prefix[n+1];
 
  vector<pair<ll,ll> > pi;
    
 f(i,n) prefix[i]=0; 

 f(i,n) cin >> a[i];  
 
 f(i,n) prefix[i+1]=prefix[i]+a[i];
     
  f(i,n)
  {
      sum = 0;
      
      for(j=i;j<n;j++)
      {
        sum+=a[j];
        temp = 0;  
        
         vector<pair<ll,ll> > tempp; 
        
          ll start=1;
          
         for(k=1;k<=n;k++)
         {
          //subarray ending with index k, can it have sum 1  
           for(l=1;l<=k;l++) 
           {
                if(prefix[k]-prefix[l-1]==sum && start<=l)
                {
                start=k+1;
                tempp.pb({l,k});    
                    temp++;
                break;    
                }
           }
         }
          
          if(temp > ans)
          {
           ans = temp;
            pi=tempp;
              
          }
      } 
  }
    
    
    cout << ans << "\n";
   
    for(auto z : pi) 
        cout << z.F << " " << z.S << "\n";
    return 0;
}