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

const int N = 1e6 + 10;
int fre[N];
int rm[N];

void solve()
{
   int n;
    cin >> n;
    
    n+=n;
    
   vi a(n);
    f(i,n) cin >> a[i];
   sort(all(a));
    
   for(int i=0;i<n-1;i++)
   {
       f(j,n) fre[a[j]] = 0;
       f(j,n) rm[a[j]] = 0;
       f(j,n) fre[a[j]]++;
       
       int x = a[i] + a[n-1];
       
       int flag = 1;
       vector<pii> res;
       
       for(int j=n-1;j>=0;j--)
       {
           if(fre[a[j]] > 0)
           {
               int t1 = a[j];
               
               if(x <= t1) 
               {
                   flag = 0;
                   break;
               }
               
               fre[t1]--;
               int t2 = x - t1;
               
               if(fre[t2] == 0)
               {
                   flag = 0;
                   break;
               }
               
               fre[t2]--;
               res.push_back({t1,t2});
               x = max(t1,t2);
           }
       }
       
       if(flag)
       {
           cout <<"YES\n";
           cout << a[i] + a[n-1] << '\n';
           for(auto x : res) cout << x.F << ' ' << x.S << '\n';
           f(v,n) fre[a[v]] = 0;
           return;
       }
   }
       
   f(v,n) fre[a[v]] = 0;
       
   cout << "NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}