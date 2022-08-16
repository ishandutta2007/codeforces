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

map<int,int> mp;

void solve()
{
   int n,m;
   cin >> n >> m;
    
   int a[m];
   f(i,m) cin >> a[i];
    
   int sum = 0;
   f(i,m) sum+=a[i];
    
   if(sum < n) 
   {
       cout << "-1\n";
       return;
   }

   int b[60] = {0}; 
   f(i,m) b[mp[a[i]]]++;
   
   int res = 0; 
   int cur = 1;
    
   for(int i=0;i<50;i++)
   {
       if(i>0) cur+=cur;
       
       if(i>0) b[i]+=(b[i-1]/2);
       int need = ((n&cur)>0);
       if(need == 0) continue;
       
       if(b[i] > 0) 
       {
           b[i]--;
           continue;
       }
       
       for(int j=i+1;j<60;j++)
       {
          if(b[j] > 0)
          {
              b[j]--;
              
              for(int k=j-1;k>=i;k--)
              {
                  res++;
                  b[k]++;
              }
              
              break;
          }
       }
     
   }
    
   cout << res << '\n'; 
}


signed main()
{
    fast;
    
    mp[1] = 0;
    int cur = 1;
    for(int i=1;;i++)
    {
        cur<<=1;
        if(cur>(1e15)) break;
        mp[cur]=i;
    }
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}