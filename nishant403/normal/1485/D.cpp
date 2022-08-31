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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


bool check(int x,int v)
{
   return (x >= 1 && x <= 1e6 && (x % v == 0));    
}

int go(int x,int y,int v)
{
   if(x == -1 && y == -1) return v;
    
   if(x == -1)  swap(x,y); 
    
   for(int i=1;(i*i*i*i) <= 1e6;i++)
     for(int j=1;(j*j*j*j) <= 1e6;j++)
   {
       int d1 = x + (i*i*i*i);
       int d2 = x - (i*i*i*i);
       int d3 = y + (j*j*j*j);
       int d4 = y - (j*j*j*j);
       
       if(y == -1)
       {
           if(check(d1,v)) return d1;
           if(check(d2,v)) return d2;
       }
       else
       {
           if(check(d1,v) && check(d3,v) && d1 == d3) return d1;
           if(check(d2,v) && check(d4,v) && d2 == d4) return d2;
           if(check(d1,v) && check(d4,v) && d1 == d4) return d1;
           if(check(d2,v) && check(d3,v) && d2 == d3) return d2;
       }
       
   }
    
    cout << x << ' ' << y << ' ' << v << '\n';exit(0);
    
    assert(1 == 0) ;
    
    return -1;
}

void solve()
{
    set<int> st;
    
    vector<int> go(17,-1);
    
    for(int i=1;i<=29;i++)
    {
        int num = 720720 - mod_pow(i,4);
        
        for(int j=1;j<=16;j++)
            if(num % j == 0) go[j] = num;
    }
    
   int n,m;
    cin >> n >> m;
    
   int a[n][m];
    f(i,n) f(j,m) cin >> a[i][j];
    
    f(i,n) f(j,m)
        if((i+j) & 1) a[i][j] = 720720;
        
    f(i,n) f(j,m)
        if(a[i][j] <= 16) a[i][j] = go[a[i][j]];
        
       f(i,n)
    {
        f(j,m) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

signed main()
{
    fast;
    
    int t = 1;
    
 //   cin >> t;
    
    while(t--)
        
    solve();
}