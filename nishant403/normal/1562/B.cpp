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

const int N = 1e7 + 10;
vector<bool> isprime(N,true);

void pre()
{
    isprime[0] = isprime[1] = false;
    
    for(int i=2;(i*i)<N;i++)
        if(isprime[i])
          for(int j=(i*i);j<N;j+=i) isprime[j] = false;
}

void solve()
{
   int n;
   cin >> n;
    
   string s;
   cin >> s;
    
   vector<int> dg;
   f(i,n) dg.pb(s[i] - '0');
    
   if(n <= 6)
   {
       pair<int,int> res = {-1,0};
       
       f(i,(1<<n))
       {
           if(i == 0) continue;
           
           int num = 0;
           
           f(j,n) if((i >> j) & 1)
               num = (num*10) + dg[j];   
           
           if(isprime[num] == false)
           {
               int rm = n - __builtin_popcount(i);
               
               if(rm > res.F) 
               {
                   res = {rm,num};
               }
           }
       }
       
       cout << n - res.F << '\n' <<res.S << '\n';
   }  
   else
   {
       //we have atmost 3 digits left
       f(i,n) if(isprime[dg[i]] == false)
       {
           cout << 1 << '\n' << dg[i] << '\n';
           return;
       }
       
       f(i,n) for(int j=i+1;j<n;j++)
       {
           int num = dg[i]*10 + dg[j];
           
           if(isprime[num] == false)
           {
               cout << 2 << '\n' << num << '\n';
               return;
           }
       }
       
       f(i,n) for(int j=i+1;j<n;j++)
           for(int k=j+1;k<n;j++)
       {
           int num = dg[i]*100 + dg[j]*10 + dg[k];
           
           if(isprime[num] == false)
           {
               cout << 3 << '\n' << num << '\n';
               return;
           }
       }
   }
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}