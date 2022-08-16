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
   int n,k;
    cin >> n>> k;
    
   string s;
   cin >> s;
 
   int flag = 0;
    
   f(i,n) if(s[i] == 'W') flag = 1;
    
   if(flag == 0)
   {
       f(i,min(n,k)) s[i] = 'W';
   }
   else
   {
    
   vector< pair<int,pii> > go;
    
   int last = -1;
    
   f(i,n)
   {
       if(s[i] == 'L') continue;
      
       if(last != -1)
       {
           if(i-last-1 > 0)
              go.pb({i-last-1,{last+1,i-1}});
       }
       
       last = i;
   }
    
   sort(go.begin(),go.end());
    
   if(go.size() == 0)
   {
       //start near W   
       int pos  = n;
       
       f(i,n) if(s[i] == 'W') pos = min(pos,i);
           
       for(int i=pos-1;i>=0;i--)
           if(k > 0) k--,s[i] = 'W';
       f(i,n) if(k > 0 && s[i] == 'L') k--,s[i] = 'W';
   } 
   else
   {
       
   for(auto x : go)
       for(int i=x.S.F;i<=x.S.S;i++)
   {
       if(k > 0) s[i] = 'W',k--;
   }
       
       int f1 = n;
       int f2 = -1;
       
       f(i,n) if(s[i] == 'W') f2 = i; 
       f(i,n) if(s[i] == 'W') f1 = min(f1,i);
           
       for(int i=f1-1;i>=0;i--) if(k > 0) s[i] = 'W',k--;
       for(int i=f2+1;i<n;i++) if(k > 0) s[i] = 'W',k--;
   }
     
    
   }
    
   int res = 0;
    
   f(i,n)
   {
       if(s[i] == 'L') continue;
       
       if(i == 0) res++;
       else if(s[i-1] == 'L') res++;
       else res+=2;
   }
    
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}