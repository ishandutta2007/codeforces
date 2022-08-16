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

bool comp(const pii &a, const pii & b)
{
 if(a.F == b.F) return a.S > b.S;   
 return a.F < b.F;   
}

void solve()
{
    int n,m,t,l,r,k;
    cin >> n >> m;
    
    vector<pii> in,out,ranges;
    vector<int> a(n);
    
    f(i,n) a[i] = 10000*(n-i);
    
    f(i,m)
    {
     cin >> t >> l >> r;
        
     l--,r--;   
        
        if(t==1) in.pb({l,r});
        else out.pb({l,r});
        
    }
    
    sort(in.begin(),in.end(),comp);
    sort(out.begin(),out.end());
    
    int val = 0;
    l = -1, r= -1;
    
    for(auto x : in)
    {
     if(x.F > r)
     {
      
      if(l!=-1)
      {
       sort(a.begin()+l,a.begin()+r+1);    
      }
         
      l = x.F;
      r = x.S;
      val+=2000; 
        
     }
     else if(x.S > r) r = x.S;
       
    }
    
    if(l!=-1)
      {
        sort(a.begin()+l,a.begin()+r+1);
      }
 
    
    for(auto x : out)
    {
        int flag = 0;
        
        for(int i =x.F;i<x.S;i++) if(a[i+1] < a[i]) flag = 1;
            
        if(flag==0)
        {
         cout << "NO"; return;   
        }
        
    }
       
    
    cout << "YES\n";
    
    f(i,n) cout << a[i] << " "; 
    
}

signed main()
{
    fast;
    int t= 1;
   // cin >> t;
    while(t--)
    solve();
}