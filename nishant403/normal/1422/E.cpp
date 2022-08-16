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
   string s;
   cin >> s;
   
   vector<pair<char,pii> > go;
   
   int last = -1;
   int cnt = 0;
   int n = s.length();
    
   f(i,n)
   {
       if(last == -1) last = i;
       
       if(s[last] != s[i])
       {
           go.pb({s[last],{last,cnt}});
           last = i;
           cnt = 0;
       }
       
       cnt++;
   }
    
   go.pb({s[last],{last,cnt}}); 
    
   int sz = go.size();
   
   vector<bool> del(sz,0); //if given a chance, should we delete or not 
    
   char nex = 'a' - 1; 
   char prev_nex  = 'a' - 2; 
    
   for(int i=sz-1;i>=0;i--)
   {
       if(go[i].S.S > 1)
       {
          if(go[i].F > nex) del[i] = 1;
          else if(go[i].F == nex && go[i].F > prev_nex) del[i] = 1;
       }
       
       if(go[i].S.S % 2 == 1 || del[i] == 0)
       {
           if(go[i].F != nex) prev_nex = nex;
           nex = go[i].F; 
       }
   }
    
   vector<pair<char,pii> > go2; //only the ones which are not deleted 
    
   f(i,sz) if(del[i] == 0) go2.pb(go[i]);
           else if(go[i].S.S % 2 == 1)
   {
       go2.pb(go[i]);
       go2.back().S.S = 1;
   }
    
   int len = 0;
   for(auto x : go2) len+=x.S.S;
     
   reverse(go.begin(),go.end());
   reverse(go2.begin(),go2.end());
   
   f(i,n)
   {
       if(go.back().S.S == 0) go.pop_back();
       
       if(go2.size() > 0 && go2.back().S.F == i)
       {
           len-=go2.back().S.S;
           go2.pop_back();
       }
       
       int ans = len;
       
       if(del[sz-(int)go.size()] == 0) ans+=go.back().S.S;
       else if(go.back().S.S % 2 == 1) ans++;
           
       cout << ans << ' ';
       
       string go3;
       
       if(ans <= 10) //get all characters
       {
           if(del[sz-(int)go.size()] == 0)
               f(v,go.back().S.S) go3+=go.back().F;
           else if(go.back().S.S % 2 == 1) go3+=go.back().F;
               
           for(int j=(int)go2.size()-1;j>=0;j--)
               f(k,go2[j].S.S) go3+=go2[j].F;
       }
       else
       {
           //take first 5 characters
           
           //first take from go if applicable
           if(del[sz-(int)go.size()] == 0)
               f(v,min(5,go.back().S.S)) go3+=go.back().F;
           else if(go.back().S.S % 2 == 1) go3+=go.back().F;   
           
           if(go3.size() < 5)
           {   
               //start taking from the back of go2
               for(int j=(int)go2.size()-1;j>=0;j--)
               {
                  if(go3.size() == 5) break;
                  int vv = min(5-(int)go3.size(),go2[j].S.S);
                  f(v,vv) go3+=go2[j].F; 
               }
           }
               
           f(v,3) go3+='.';
           
           //take last 2 characters
           
           if(!go2.empty())
           {
               if(go2.size() == 1 && go2[0].S.S == 1)
               {
                  go3+=go.back().F;
                  go3+=go2[0].F;
               }
               else if(go2[0].S.S == 1)
               {
                  go3+=go2[1].F;
                  go3+=go2[0].F;
               }
               else 
               {
                  go3+=go2[0].F;
                  go3+=go2[0].F;
               }
           }
           else
           {
               go3+=go.back().F;
               go3+=go.back().F;
           }
       }
       
       cout << go3 << '\n';
       
       go.back().S.S--;    
   }
}  

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}