#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for (i=0;i<n;i++)

int main()
{
 int n,q,a,b,i,j,complete=0,ans=9999999,kk=99999,cover=0;
    
    cin >> n >> q;
    
  vector<pair<int,int> > pai;   
    int ones[n+1];
    int total[n+2];
    
    f(i,n+2) total[i]=0;
    f(i,n+1) ones[i]=0;
    
   f(i,q) 
   {
       cin >> a >> b;
       pai.push_back({a,b});
       
       total[a]++;
       total[b+1]--;
       
   }
    
    f(i,n) total[i+2]+=total[i+1];
    
    complete=n;
    f(i,n) if (total[i+1]==0) complete--; 
    
        
      
        
        
    f(i,q)
    {
        
     for(int z = pai[i].first ;z<=pai[i].second ;z++) 
     {
      total[z]--;  
      if(total[z]==0) cover ++;  
     }  
       
      for(int z=1;z<=n;z++) 
      {  if(total[z] == 1) ones[z]++;
          ones[z]+=ones[z-1];
    
      }
     
        
        
    for(j=i+1;j<q;j++)
    {
       kk=min(kk, ones[pai[j].second]-ones[pai[j].first-1]);
      
    }
        
        
     ans=min(ans,cover+kk);   
    //restore
        for(int z = pai[i].first ;z<=pai[i].second ;z++) total[z]++;  
       f(j,n) ones[j+1]=0; 
        kk=99999;
        cover=0;
        
        
    }
    
        cout << complete - ans;
}