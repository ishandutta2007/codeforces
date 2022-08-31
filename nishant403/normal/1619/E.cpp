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


void solve()
{
   int n;
    cin >> n;
    
   int a[n];
   f(i,n) cin >> a[i];
   sort(a,a+n);
    
   map<int,int> mp;
   f(i,n) mp[a[i]]++;
    
   vector<int> vs;
    
   int tmp = 0;
   int ptr = 0;
   int avail = -1;
    
   for(int i=0;i<=n;i++)
   {
       if(tmp == -1)
       {
           cout << tmp << ' ';
           continue;
       }
       
       while(ptr < n && a[ptr] < i)
       {
           if(ptr > 0 && a[ptr - 1] == a[ptr]) vs.pb(a[ptr]);
           ptr++;
       }
       
       while(avail < i - 1)
       {
           //try to create avail + 1 
           if(mp[avail + 1] > 0) avail++;
           else if(vs.size() > 0)
           {
               tmp += avail + 1 - vs.back();
               vs.pop_back();
               avail++;
           }
           else break;
       }
       
    //   cout << "DEBUG  " << i << ' ' << avail <<'\n';
       
       if(avail != i-1) 
       {
           tmp = -1;
           cout << -1 << ' ';
       }
       else cout << tmp + mp[i] << ' ';
   }
    
   cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}