#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int r)
{
    uniform_int_distribution<int> uid(0,r-1);
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

const int N = 2e5 + 10;
const int M = (1LL<<15);

int F[M];
int a[N];
int b[N];
int n,m,p;
int res = 0;
int rc = 0;

void update(int x)
{
    vector<int> map_bit(60,0);
    vector<int> inv_map(60,0);
    
    int idx = 0;
    
    f(j,m)
    {
        if((x>>j) & 1)
        {
            map_bit[j] = (1LL<<idx);
            inv_map[idx] = j;
            idx++;
        }
    }
    
    f(i,n)
    {
        b[i] = 0;
        
        f(j,m)
        {
            if((a[i] >> j) & 1)
            {
                b[i] |= map_bit[j];
            }
        }
    }
    
   // https://codeforces.com/blog/entry/45223
   int ii = (1LL<<idx) - 1; 
    
   f(i,(1<<idx)) F[i] = 0;
   f(i,n) F[b[i]^ii]++; 
    
   for(int i = 0;i<idx; ++i) 
       for(int mask = 0; mask < (1<<idx); ++mask)
        if(mask & (1<<i))
           F[mask] += F[mask^(1<<i)];
       
   int temp_res = 0;
   int temp_cc = 0;
    
   f(i,(1<<idx))
   {
       if(F[i] >= ((n+1)/2))
       {
           int i2 = (i^ii);
           int cc = __builtin_popcount(i2);
              
           if(cc > temp_cc)
           {
               temp_cc = cc;
               temp_res = i2;
           }
       }
   }
    
    
   //convert to original mask
   if(temp_cc > rc)
   {
       rc = temp_cc;
       res = 0;
       
       f(j,idx)
       {
           if((temp_res>>j) & 1)
           {
               res |= (1LL<<inv_map[j]);
           }
       }
   }
}

void solve()
{
   cin >> n >> m >> p;
    
   f(i,n)
   {
       string s;
       cin >> s;
       
       f(j,m)
       {
           if(s[j] == '1') a[i] |= (1LL<<j);
       }
   }
    
   random_shuffle(a,a+n,getRand);
   random_shuffle(a,a+n,getRand);
   random_shuffle(a,a+n,getRand);
   random_shuffle(a,a+n,getRand);
    
   f(i,min(n,(int)30)) update(a[i]); 
    
   f(j,m)
   {
       cout << (res % 2);
       res /= 2;
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