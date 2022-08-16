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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

void solve()
{
   int n;
    cin >> n;
    
   int r1,r2,r3;
    cin >> r1 >> r2 >> r3;
    
   int d;
    cin >> d;
    
   int a[n];
    f(i,n) cin >> a[i];
   
   int res = 0;
    
   vector<int> done(n,0); 
   vector<int> nodone(n,0); 
    
   int g = min(r1,min(r2,r3));
    
   f(i,n)
   {
       done[i] = a[i]*min(r1,r3) + min(r3 , min(r1,r2) + d + d + min(r1,r2));
       done[i] = min(done[i], r2 + d + d + min(r1,min(r2,r3)));
       
       nodone[i] = a[i]*min(r1,r3) + min(r1,r2) + g;
       nodone[i] = min(nodone[i],r2 + g);
       nodone[i] = min(nodone[i], a[i]*min(r1,r3) + r3); 
       
       if(i > 0) done[i]+=d;
       if(i > 0) nodone[i]+=d;
   }
    
    vi pref(n,0);
    
    f(i,n) 
    {
       if(i == 0) pref[i] = done[i];
       else if(i == 1)  pref[i] = min(done[0] + done[1], nodone[0] + nodone[1] + d + d);
       else pref[i] = min(pref[i-1] + done[i], pref[i-2] + nodone[i-1] + nodone[i] + d + d);
    
       if(i == n-1) pref[i] = min(pref[i],pref[i-1] + nodone[i] + d + d);
           
       if(i == n-1 && n > 2) pref[i] = min(pref[i],pref[i-2] + nodone[i-1] + done[i] + d);   
           
    }
    
    cout << pref[n-1];
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}