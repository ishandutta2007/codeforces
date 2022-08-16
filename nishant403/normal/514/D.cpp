#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
 int i,j,n,k,m;
    cin >> n >> m >> k;
    
    int a[n][m];
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          cin >> a[i][j];
    
        
    int first = 0;
    int ans = 0;
    int data[m];
    int sum = 0;
    
    deque<int> dq[m];
    
   for(i=0;i<m;i++) data[i]=0;
    
    
    
    for(int last=0;last<n;last++)
    {
        
      for(i=0;i<m;i++) 
      {
       while(!dq[i].empty() && a[dq[i].back()][i] <= a[last][i] ) dq[i].pop_back();   
       dq[i].push_back(last);   
      }
       
        sum=0;
      for(i=0;i<m;i++) if(!dq[i].empty()) sum+=a[dq[i].front()][i];        
        
     while(sum>k) 
     {
         sum = 0;
         
      for(i=0;i<m;i++) if(!dq[i].empty() && dq[i].front()==first) dq[i].pop_front();
          
      for(i=0;i<m;i++) if(!dq[i].empty())  sum+=a[dq[i].front()][i];        
      
      first++; 
     }
      
        
     if(last-first+1 > ans)
     {
         ans = last-first+1;
       for(i=0;i<m;i++) if(!dq[i].empty())  data[i]=a[dq[i].front()][i];  
     }
      
     }
    
   
    for(i=0;i<m;i++) cout << data[i] << " ";
   }