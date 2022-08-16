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

int go(int x)
{
    if(x == 0) return 0;
    return (x % 10) + go(x/10);
}

int pw[19];

void solve()
{
   int n,s;
    cin >> n >> s;
    
   if(go(n) <= s)
   {
       cout << 0 << '\n';
       return;
   }
    
   vi pref;
    
   int temp = n;
    
   while(temp > 0)
   {
       pref.pb(temp % 10);
       temp/=10;
   }
    
   int dg = pref.size(); 
    
   reverse(pref.begin(),pref.end()); 
    
   int res = pw[dg] - n; 
    
   int sum  = 0;
   int num = 0; 
    
   f(i,dg)
   {
       //increase the current digit
       if(pref[i] < 9) 
       {
           if(sum + pref[i] + 1 <= s)
           {
               //create the new number   
               int temp = num + (pref[i]+1)*pw[dg-i-1];
               res = min(res, temp - n);
           }
       }
       
       num+=pw[dg-i-1]*pref[i];
       sum+=pref[i];
   }
    
    
    
   cout << res << '\n'; 
}

signed main()
{
    pw[0] = 1;
    
    for(int i=1;i<=18;i++) pw[i] = (pw[i-1]*10);
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}