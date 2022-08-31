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
#define bye { check = 0; return; } 

vi ans;
bool check;

void insert(int n,int a,int b)
{  
   f(i,n)
   {
      ans.pb(a); ans.pb(b);   
   }
}

void solve(int a,int b,int c,int d,int start)
{
  if(start == 0)
  {
     if(a>b+1) bye
     
     if(a == b+1)
     {
         if(c>0 || d>0) bye
         
         insert(b,0,1);
         ans.pb(0); return;
     }
      
     insert(a,0,1); b-=a; a=0;   
  }
  else
  {
    if(a>=b) bye     
    insert(a,1,0); b-=a; a=0;  
  }
    
     if(b>c) bye 
      
     insert(b,2,1); c-=b; b=0;
     
     if(c == 0)
     {
        if(d == 0) return;
        else bye
     }
    
     ans.pb(2); c--;
         
     if(d == c+1 || d == c)
     {
        insert(c,3,2); d-=c; c=0;
        if(d == 1) ans.pb(3);
        return;
     }
     else bye 
}

signed main()
{
    fast;
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    check = 1;
    solve(a,b,c,d,0);
    
    if(check == 1)
    {
        cout<<"YES\n"; 
        for(auto x : ans) cout << x <<" ";
        return 0;
    }
   
    check = 1; ans.clear();    
    solve(d,c,b,a,0);
    
    if(check == 1)
    {
      cout<<"YES\n"; 
      for(auto x : ans) cout << 3-x <<" "; 
      return 0;  
    }
    
    check = 1; ans.clear();
    solve(a,b,c,d,1);
   
     if(check == 1)
    {
      cout<<"YES\n"; 
      for(auto x : ans) cout << x <<" "; 
      return 0;  
    }
    
    check = 1; ans.clear();
    solve(d,c,b,a,1);
   
    if(check == 1)
    {
      cout<<"YES\n"; 
      for(auto x : ans) cout << 3-x <<" "; 
      return 0;  
    }
    
    cout<<"NO\n";
}