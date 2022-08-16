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

void compress(vector<int> & a)
{
   vector<int> b = a;
   sort(b.begin(),b.end());
   for(auto & x : a) x = lower_bound(b.begin(),b.end(),x) - b.begin();   
}

void solve()
{
   int n;
   cin >> n;
    
   vector<int> a(n);
   f(i,n) cin >> a[i];
   compress(a);
      
   vi fre(n+1,0);
   vi nex(n+1,n);
   vi prev(n+1,-1);
    
   f(i,n) fre[a[i]]++;
   
   for(int i=n-1;i>=1;i--)
   {
       if(fre[i] > 0) nex[i-1] = i;
       else nex[i-1] = nex[i]; 
   }
    
   int res = 0; 
   
   for(int i=0;i<n;i++)
   {
       if(fre[i] > 0) prev[i+1] = i;
       else prev[i+1] = prev[i];
   }
    
   vi pref(n+1,0); 
    
   f(i,n) pref[i] = 0;
   vi dp(n,0); 
    
   //a[i] is completely included.  
   f(i,n)
   {
       pref[a[i]]++;
       
       dp[a[i]]++;
           
       if(pref[a[i]] == 1)
       {  
           if(prev[a[i]] != -1)
               if(pref[prev[a[i]]] == fre[prev[a[i]]]) dp[a[i]]+=dp[prev[a[i]]];
               else dp[a[i]]+=pref[prev[a[i]]];
       }
       
       if(pref[a[i]] == fre[a[i]]) res = max(res,dp[a[i]] + fre[nex[a[i]]] - pref[nex[a[i]]]);
       
       res = max(res,pref[a[i]] + fre[nex[a[i]]] - pref[nex[a[i]]]);
       res = max(res,dp[a[i]]); 
   }
    
   cout << n - res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}