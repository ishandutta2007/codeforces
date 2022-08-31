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
 int a,b;
    
 cin >> a >> b;
    
 if(a==b) cout << (a) << 1 <<" "<<b<<2;
 else if(a==9 && b==1) cout << a <<" "<<10;   
 else if(a+1 == b)
 {
  cout<<a<<9 <<" "<<b<<0;   
 }
 else cout << -1;   
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}