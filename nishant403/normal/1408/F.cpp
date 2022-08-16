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

vector<pii> res;

//maximum power of 2 <= n
int mx(int n)
{
    int res = 1;
    
    while((res*2) <= n)
    {
        res = (res*2);
    }
    
    return res;
}

void go(int l,int r)
{
    if(l == r) return;
    
    int len = (r-l+1)/2;
    
    go(l,l+len-1);
    go(l+len,r);

    for(int i=l;i<=l+len-1;i++) res.pb({i,i+len});
}

void solve()
{
   int n;
    cin >> n;
    
   vector<pair<int,vi> > dat; 
    
   int l = 1;
    
   pair<int,vi> big;
   int flag = 0;
    
   while(n > 0)
   {
       int sz = mx(n);
       
       vi temp;
       f(i,sz) temp.pb(l+i);
       
       if(flag == 1) dat.pb({sz,temp});
       else
       {
           flag = 1;
           big = {sz,temp};
       }
       
       go(l,l+sz-1);
       l = l + sz;
       n -= sz;
   }
    
   while(dat.size() > 1)
   {
       auto x1 = dat.back(); dat.pop_back();
       auto x2 = dat.back(); dat.pop_back();
       
       if(x2.F == x1.F)
       {
           f(i,x2.F)
           {
               res.pb({x2.S[i],x1.S[i]});
               x2.S.pb(x1.S[i]);
           }
           
           x2.F+=x2.F;
           dat.pb(x2);
       }
       else
       {
           if(x2.F < x1.F) swap(x1,x2);
      
       if(x2.F > big.F) swap(x2,big);
       
       //x2 has more size
       
       f(i,x1.F) 
       {
           res.pb({big.S.back(),x1.S[i]}); 
           x1.S.pb(big.S.back());
           big.S.pop_back();
       }
       
       int mov = x1.F;
       x1.F+=mov;
       big.F-=mov;
       
           
           dat.pb(x2);
           dat.pb(x1);
       }
   }
    
   cout << res.size() << '\n';
   for(auto x : res)cout << x.F << ' ' << x.S << '\n';    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}