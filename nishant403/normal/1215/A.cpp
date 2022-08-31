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
  int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    
  if(k1 > k2) swap(k1,k2),swap(a2,a1);
    
  int nn = n;
  nn-=(a1*k1)-a1;
  nn-=(a2*k2)-a2;
    
  int mi = 0;  
    
  if(nn <= 0) mi = 0;
  else mi = min(a1+a2,nn);  
     
  int ma = min(a1,n/k1);  
  int left = n - (ma*k1);  
    
  if(left > 0) ma+=min(a2,left/k2);   
  
    
  cout << mi <<" "<<ma;  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}