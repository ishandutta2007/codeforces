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
    
  int a[4*n];
  f(i,4*n) cin >> a[i];
    
  sort(a,a+4*n);
    
  int area = (a[0]*a[(4*n)-1]);  
    
 
  int l = 0,r = (4*n)-1;
                   
  while(l<r)
  {
      if(a[l] != a[l+1]) {cout<<"NO\n"; return;}
      if(a[r] != a[r-1]) {cout << "NO\n"; return;}
      
      int arr= a[l]*a[r];
      
      if(arr != area) {cout << "NO\n"; return;}
      l+=2;
      r-=2;
  }
                   
                   cout << "YES\n";
                   
      
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}