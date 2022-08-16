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
  int n;
  cin >> n; 
 
  int a[n];
  vi p(n,-1);
    
  f(i,n) cin >> a[i];
    
  f(i,n) if(a[i] < i+1)
  {
      cout<<-1<<'\n';
      return;
  }
    
  vector<bool> used(n+1,0);
    
  f(i,n)
      if(!used[a[i]]) p[i] = a[i],used[a[i]] = 1;
  
  int l = 1;
    
  f(i,n)
  {
      if(p[i] != -1) continue;
      
      while(used[l] == 1 && l<=n) l++;
      
      if(l==n+1) break;
      
      p[i] = l;
      l++;
  }
     
  f(i,n) cout << p[i] <<" ";cout<<'\n';  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}