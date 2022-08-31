#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
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
   int n,m,p;
    cin >> n >> m >> p;
    
  int a[n];
  int b[m];
   
  f(i,n) cin >> a[i];
  f(i,m) cin >> b[i];
    
  int id1 = -1;
  int id2 = -1;
    
  f(i,n) if(a[i] % p != 0 && id1 == -1) id1 = i;
  f(i,m) if(b[i] % p != 0 && id2 == -1) id2 = i;
     
  cout << id1 + id2 << '\n';    
      
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}