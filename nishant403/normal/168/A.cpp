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
  int n,x,y;
 cin >> n >> x >> y;
    
    int p = n - x;
    
    // (x+c)/n * 100 = y
    
    if( x*100 >= y*n)
    {
      cout << 0;
    }
    else
    {
      cout << ceil(((double)(y*n)/100)-x);   
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