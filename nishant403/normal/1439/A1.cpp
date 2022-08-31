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

const int N = 105;

string s[N];
int n,m;
vector<vector<pii> > res;

void inv(int i,int j)
{
    if(s[i][j] == '1') s[i][j] = '0';
    else s[i][j] = '1';
}

void apply(int i,int j)
{
    inv(i,j);
    inv(i+1,j);
    inv(i+1,j+1);
    
    res.pb({{i,j},{i+1,j},{i+1,j+1}});  
} 

void apply(pii x,pii y,pii z)
{
    inv(x.F,x.S);
    inv(y.F,y.S);
    inv(z.F,z.S);
    res.pb({x,y,z});
}

void solve()
{
   res.clear();
    
   cin >> n >> m;
   f(i,n) cin >> s[i];
 
   for(int i=0;i<n-2;i++)
   {
       for(int j=0;j<m-2;j++)
         if(s[i][j] == '1') apply(i,j);
           
       if(s[i][m-2] == '1' && s[i][m-1] == '0') apply(i,m-2);
       else if(s[i][m-2] == '1')
          apply({i,m-2},{i,m-1},{i+1,m-1});
       else if(s[i][m-1] == '1')
          apply({i+1,m-2},{i,m-1},{i+1,m-1});
   }
    
   for(int i=0;i<m-2;i++)
   {
       if(s[n-2][i] == '1' && s[n-1][i] == '1') apply(n-2,i);
       else if(s[n-2][i] == '1')
           apply({n-2,i},{n-2,i+1},{n-1,i+1});
       else if(s[n-1][i] == '1')
           apply({n-1,i},{n-2,i+1},{n-1,i+1});
   }
    
   //now only 2x2 left
    
   int sum = 0;
   f(i,2) f(j,2) sum+=(s[n-1-i][m-j-1] - '0');
   
    pii p = {n-2,m-2};
    pii q = {n-2,m-1};
    pii r = {n-1,m-2};
    pii t = {n-1,m-1};
    
    if(sum == 4) 
    {
        apply(n-2,m-2);
        sum-=3;
    }
    
    if(sum == 1)
    {
        if(s[n-1][m-1] == '1') apply(q,r,t);
        else apply(p,q,r);
        sum = 2;
    }
    
    if(sum == 2)
    {
        vector<pii> zr;
        vector<pii> on;
        
        if(s[n-2][m-2] == '1') on.pb(p);
        else zr.pb(p);
    
        if(s[n-2][m-1] == '1') on.pb(q);
        else zr.pb(q);
    
        if(s[n-1][m-2] == '1') on.pb(r);
        else zr.pb(r);
    
        if(s[n-1][m-1] == '1') on.pb(t);
        else zr.pb(t);
    
        sum = 3;
        
        apply(zr[0],zr[1],on[0]);
    }
    
    if(sum == 3)
    {
        vector<pii> zr;
        vector<pii> on;
        
        if(s[n-2][m-2] == '1') on.pb(p);
        else zr.pb(p);
    
        if(s[n-2][m-1] == '1') on.pb(q);
        else zr.pb(q);
    
        if(s[n-1][m-2] == '1') on.pb(r);
        else zr.pb(r);
    
        if(s[n-1][m-1] == '1') on.pb(t);
        else zr.pb(t);
        
        apply(on[0],on[1],on[2]);
    }
    
    cout << res.size() << '\n';
    
   for(auto x : res)
   {
       for(auto y : x) cout << y.F + 1 << ' ' << y.S + 1 << ' ';
       cout << '\n';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}