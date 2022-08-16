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
    int n,k;
    cin >> n >> k;
    
    int odds = 0;
    
    int a[n];
    
    f(i,n) cin >> a[i];
    
    f(i,n) odds+=a[i]%2;
    
    
    if(odds < k ){
     cout << "NO\n"; return;   
    }
    
    if( (odds - k)%2 !=0) 
    {
      cout << "NO\n"; return;   
    }
    
    int done = 0;
    
    cout << "YES\n";
    
    f(i,n)
    {
        if(done ==k-1) break;
     
        if(a[i]%2==1) { cout << (i+1) << " "; done++; }
    }
    cout << n ;
    cout << "\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}