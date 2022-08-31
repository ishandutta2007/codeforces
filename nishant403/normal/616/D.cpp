#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
 int i,j,n,k;
    
   scanf("%lld %lld",&n ,&k); 
    
    int a[n];
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    
    int first = 0;
    int conv = 0;
    int ans = 0;
    map<int,int> m;
    
    int l1,r1;
    
    for(int last=0;last<n;last++)
    {
     if(m.find(a[last])!=m.end() ) m[a[last]]++;
      else m[a[last]]=1;
     
     while(m.size()>k) 
     {
      if(m[a[first]]==1) m.erase(a[first]);   
      else m[a[first]]--;   
         
        first++; 
     }
           
     if(last-first+1 > ans)
     {
      ans=last-first+1;
         l1=first+1;
         r1=last+1;
     }
      
      }
    
   
    cout << l1 << " "<< r1;
}