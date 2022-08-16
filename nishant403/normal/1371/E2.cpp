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

const int N = 1e5 + 10;
int n,p;
int a[N];

//power of p in n!
int max_pow(int n,int p)
{
    if(n < p) return 0;
    
    return (n / p) + max_pow(n/p,p);
}

int check(int x)
{
   int ways = 0;
       
   vector<int> place(n,0);

   f(j,n)
   {
       if(a[j] <= x) place[0]++;
       else if(a[j] > x + n-1)
       {
           return -1;
       }
       else
       {
           place[a[j] - x]++;
       }
   }

   int places = 0;

   for(int j=n-1;j>=0;j--)
   {
       places++;

       if(places < place[j])
       {
           return -1;
       }
       
       for(int k=0;k<place[j];k++)
       {
           ways += max_pow(places,p);
           ways += max_pow(place[j],p);
           ways += max_pow(places-place[j],p);
       }

       places -= place[j];
   }

   return (ways == 0);
}

void solve()
{
   cin >> n >> p;
   f(i,n) cin >> a[i];
    
   int l = 1;
   int r = 1e9;
   int res = r;
    
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       int rs = check(mid);
       
       if(rs == -1)
       {
           l = mid + 1;
       }
       else if(rs == 0)
       {
           r = mid - 1;
       }
       else 
       {
           res = mid;
           r = mid - 1;
       }
   }
    
   l = 1;
   r = 1e9;
   int res2 = l;
    
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       int rs = check(mid);
       
       if(rs == -1)
       {
           l = mid + 1;
       }
       else if(rs == 0)
       {
           r = mid - 1;
       }
       else 
       {
           res2 = mid;
           l = mid + 1;
       }
   }
    
   if(res > res2)
   {
       cout << 0;
   }
   else
   {
       cout << res2 - res + 1 << '\n';
       for(int i=res;i<=res2;i++) cout << i << ' ';
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}