#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

bool comp(const pii & a,const pii & b)
{
 if(a.F == b.F) return a.S > b.S;
 return a.F < b.F;
}

signed main()
{
    int n,k,m,a,x;
    
    cin >> n >> k >> m >> a;
    
    pair<int,int> s;
    s={0,99999999};
    
    vector<pair<int,int> > cn(n,s);
    
    f(i,a)
    {
        cin >> x;
        cn[x-1].F++;
        cn[x-1].S=i;
    }
    
    vector<int> ans(n,0);
    
    f(i,n)
    {
        
     int check = 0;
        
     f(j,n)
     {
        if(j!=i && cn[j].F >= cn[i].F+m-a)
        {
           if(cn[j].F == 0) continue; 
            
           if(cn[j].F == cn[i].F+m-a)
          {
           if(a==m && cn[j].S > cn[i].S) continue;
          }
            
           check++; 
        }
     }
        
        if( check >= k) { ans[i] = 3; continue; }   
        else if (a==m && cn[i].F == 0) { ans[i] = 3; continue; }
        
     //now check if he will be selected regardless of other votes   
     vector<pair<int,int> > vv;
        
     f(j,n) if(j!=i) vv.pb(cn[j]);
        
     sort(vv.begin(),vv.end(),comp);   
         
     int votes = m-a;
     int done = 0;   
        
     for(int j=n-2;j>=0;j--)  
     {
       if(vv[j].F > cn[i].F) done++;   
       else if(vv[j].F == cn[i].F)
       {
        if(vv[j].S > cn[i].S)
        {
         if(votes <= 0) continue;
         votes--;   
        }
        done++;   
       }
       else
       {
        int need = cn[i].F+1-vv[j].F;   
           
        if(votes < need) continue;
           
        votes-=need;
        done++;
       }
         
     }
      
     if(done < k && cn[i].F > 0 ) ans[i] = 1;   
         
     if(ans[i] == 0) ans[i] =2;   
    }
    
    f(i,n) cout << ans[i] <<" ";
    
}