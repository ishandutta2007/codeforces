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

int fun(int a,int b,int c)
{ 
  return ((a-b)*(a-b)) + ((b-c)*(b-c)) + ((c-a)*(c-a)); 
}

int go(vi & a,vi & b,vi & c)
{
    int id1 = 0;
    int id3 = 0;
    
    int res = 4e18;
    
    for(auto x : b)
    {
        while(id1 < (int)a.size()-1 && a[id1+1] <= x) id1++;
        while(id3 < (int)c.size()-1 && c[id3] < x) id3++;
        
        res = min(res,fun(x,a[id1],c[id3]));
    }
    
    return res;
}

void solve()
{
   int a,b,c;
    cin >> a >> b >> c;
    
   vi a1(a);
   vi b1(b);
   vi c1(c);
    
  f(i,a) cin >> a1[i];
  f(i,b) cin >> b1[i];
  f(i,c) cin >> c1[i];
  
  sort(a1.begin(),a1.end());
  sort(b1.begin(),b1.end());
  sort(c1.begin(),c1.end());
    
  int res = 4e18; 
    
  res = min(res,go(a1,b1,c1));
  res = min(res,go(b1,a1,c1));
  res = min(res,go(b1,c1,a1));
  res = min(res,go(a1,c1,b1));
  res = min(res,go(c1,b1,a1));
  res = min(res,go(c1,a1,b1));
    
  cout << res << '\n';  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}