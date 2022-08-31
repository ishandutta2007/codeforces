#include <bits/stdc++.h>
using namespace std;

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
    
   string s;
    cin >> s;
    
   vi go;
    
   char last = s[0];
   int cnt = 0; 
    
   f(i,n)
   {
       if(s[i] != last)
       {
           go.pb(cnt);
           cnt = 0;
       }
       
       cnt++;
       last = s[i];
   }
    
   go.pb(cnt); 
    
   vector<pii> st;
    
   int sz = go.size();
    
   f(i,sz) 
      if(go[i] > 1) st.pb({go[i],i});
    
   reverse(st.begin(),st.end());    
       
   int res = 0; 
    
   f(i,sz)
   {
       if(go[i] == 0) continue;
       
       if(st.empty())
       {
          int id = -1; 
           
          for(int j=i+1;j<sz;j++)
          {
              if(go[j] > 0) 
              {
                  id = j;
                  break;
              }
          }
           
          res++;
          
          if(id == -1) break; 
          else i = id; 
          continue;
       }
       
       
       res++;
       go[st.back().S]--;
       st.back().F--; 
       
       if(st.back().F == 1) st.pop_back();   
       if(!st.empty() && st.back().S == i) st.pop_back();
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