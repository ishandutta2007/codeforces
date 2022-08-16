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

void conv(string & s)
{
    int n = s.length();
    
    int one[n];
    int zero[n];
    
    int oo = n;
    int zz = n;
    
    for(int i=n-1;i>=0;i--)
    {
        one[i] = oo;
        zero[i] = zz;
        
        if(s[i] == '0') zz = i;
        else if(s[i] == '1') oo = i;
    }
    
    for(int i=0;i<n-1;i++)
    {
        if(s[i] == '1' && one[i] <= zero[i]) s[i+1] = '1';
        else if(s[i] == '0' && zero[i] <= one[i]) s[i+1] = '0';
    }
    
    char first = '?';
    
    for(auto x : s) if(x != '?') 
    {
        first = x; break;
    }
    
    for(auto & x : s) if(x == '?') x = first;
                      else break;
}

void solve()
{
   int n;
    cin >> n;
    
   string s;
    cin >> s;
    
   int fa = 0,fb = 0;
    
   for(auto x : s) 
       if(x == '0') fa = 1;
       else if(x == '1') fb = 1; 
       
   if(fa == 0 || fb == 0)
   {
       for(int i=1;i<=n;i++)
           cout << (n/i) << ' ';
       return;
   }
    
   conv(s); 
   
   vector<pair<char,pii> > go; //value frequency form
    
   char last = '8';
   int cnt = 0;
    
   for(int i=0;i<n;i++)
   {
       auto x = s[i];
       
       if(x != last && cnt > 0) go.pb({last,{cnt,i-cnt}});
       
       if(x != last) cnt = 0;
       
       last = x;
       cnt++;
   }
    
   go.pb({last,{cnt,n-cnt}});
       
   vector<pair<pii,pii> > cur;
   
   for(int i=0;i<go.size();i++) 
   {
       if(go[i].F == '?') continue;
       
       cur.pb({go[i].S,{0,0}});
       
       if(i > 0 && go[i-1].F == '?') cur.back().S.F = go[i-1].S.F;
       if(i != (int)go.size() - 1 && go[i+1].F == '?') cur.back().S.S = go[i+1].S.F;
   }
    
    for(int l=1;l<=n;l++)
    {
        int res = 0;
        int carry = 0;
        
        for(int i=0;i<cur.size();i++)
        {
            auto x = cur[i];
            
            int tot = x.F.F + x.S.F + x.S.S;
         
            if(i > 0 && cur[i-1].F.S + cur[i-1].S.S + cur[i-1].F.F == cur[i].F.S) tot += carry;
            
            res+=(tot/l);
            
            int nouse = (tot % l);
            
            if(nouse > x.S.S) carry = 0;
            else carry = nouse - x.S.S;
        }
        
        cout << res << ' ';
        
        vector<pair<pii,pii> > nex;
        
        for(int i=0;i<cur.size();i++)
        {
            auto x = cur[i];
            
            int potential = x.F.F + x.S.F + x.S.S;
            
            if(potential > l) nex.pb(x);
        }
        
        swap(nex,cur);
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