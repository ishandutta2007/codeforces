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
   int n;
    cin >> n;
    

   vi divs;
    
   int temp = n;
    
   for(int i=1;(i*i) <= temp;i++)
   {
       if(temp % i == 0) 
       {
           divs.pb(i);
           if((i*i) != temp) divs.pb(temp/i);
       }
   }
    
   int sz = (divs.size());
   vi vis(sz,0);
   vis[0] = 1;
    
   vi primes; 
    
   temp = n; 
    
   for(int i=2;(i*i)<=temp;i++)
   {
       if(temp % i == 0)
       {
           while(temp % i == 0) temp/=i;
           primes.pb(i);
       }
   }
    
   if(temp > 1) primes.pb(temp); 
    
   vi res; 
    
   if(primes.size() > 2)
   {
      for(int i=0;i<primes.size();i++)
      {
       int n1 = (primes[i]);
         
       if(i > 0) n1*=primes[i-1];
       else n1*=primes.back();
          
       int n2 = (primes[i]);
          
       if(i < (int)primes.size() - 1) n2*=primes[i+1];
       else n2*=primes[0];   
         
       int idd = -1;   
          
       for(int j=0;j<divs.size();j++)
       {
           if(vis[j] == 0 && divs[j] != n1 && divs[j] != n2 && divs[j] % primes[i] == 0)
            res.pb(divs[j]),vis[j] = 1;   
       
           if(divs[j] == n2) idd = j; 
       }
          
       res.pb(divs[idd]); 
       vis[idd] = 1;
          
      }
   }
   else if(primes.size() == 1 || (int)divs.size() == 4)
   {
       for(auto x : divs) if(x != 1) res.pb(x);
   }
   else
   {
       int save1 = -1;
       int save2 = -1;
       
       for(int i=0;i<divs.size();i++)
       {
           if(divs[i] % primes[0] == 0 && divs[i] % primes[1] == 0)
           {
               if(save1 == -1) save1 = divs[i], vis[i] = 1;
               else if(save2 == -1)
               {
                   save2 = divs[i];
                   vis[i] = 1;
                   break;
               }
           }
       }
       
       res.pb(save1);
       
       for(int i=0;i<divs.size();i++)
       {
          if(vis[i] == 1) continue;
          if(divs[i] % primes[0] != 0) continue;
          res.pb(divs[i]);
          vis[i] = 1;
       }
       
       res.pb(save2);
       
       for(int i=0;i<divs.size();i++)
       {
          if(vis[i] == 1) continue;
          res.pb(divs[i]);
          vis[i] = 1;
       }
   }
   
   for(auto x : res) cout << x << ' ';
   cout << '\n';
   
   int ans = 0;
    
   for(int i=1;i<res.size();i++) if(__gcd(res[i],res[i-1]) == 1) ans++;
   if(__gcd(res[0],res[(int)res.size()-1]) == 1) ans++;
       
   cout << ans << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}