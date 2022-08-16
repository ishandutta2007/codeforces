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
    f(i,n) cin >> a[i];
    
   int sum = 0;
    f(i,n) sum+=a[i];
    
   if(sum % n > 0) 
   {
       cout << -1 << '\n';
       return;
   }
    
   vector<pair<pii,int> > ops; 
    
   //in 2n operations, make a[i] = 0 , for each i > 0
   for(int i=1;i<n;i++)
   {
       //first make a[i] is multiple of i
       int need = (a[i] % (i+1));
       need = (i+1) - need;
       need %= (i+1);
       
       ops.pb({{1,i+1},need});
       ops.pb({{i+1,1},(a[i] + need)/(i+1)});
   }
    
   //in n operations, distribute equal amount from a[0]
   int xx = (sum / n); 
   
   for(int i=1;i<n;i++) ops.pb({{1,i+1},xx});
       
   cout << ops.size() << "\n"; 
    
   for(auto x : ops)
       cout << x.F.F << ' ' << x.F.S << ' ' << x.S << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}