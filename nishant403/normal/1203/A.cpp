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
  int n,x;
  cin >> n;
      
  int a[n];
  int pos ;   
    
  f(i,n) cin >> a[i];
    
 int f1 = 1;  
    
  f(i,n) if(a[i] == 1) pos = i;  
 
  f(i,n)
  {
      if(a[pos] != i+1) {f1=0; break; }
    pos++;
    if(pos==n) pos=0;     
  }
    
  f(i,n) if(a[i] == n) pos = i;  
   
  int f2=1; 
    
  f(i,n)
  {   
    if(a[pos] != n-i) { f2=0; break; }
    pos++;
    if(pos==n) pos=0;     
  }  
    
    
    if(f1||f2) cout << "YES\n";
    else cout << "NO\n";
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}