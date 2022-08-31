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

const int N = 1e5 + 100;
int fre[N];
int a[N];

vector<int> lastprime(N,-1);

void sieve_lastprime()
{
  lastprime[0] = lastprime [1] = 0;
    
  //-1 is prime
    
  for(int i=2;i<N;i++)
  {
    if(lastprime[i] == -1)
        for(int j=i*i;j<N;j+=i) 
            lastprime[j] = i;  
  }
}

vector<int> mobius(N);

void sieve_mobius()
{
  sieve_lastprime();  
    
  mobius[0] = 0;
  mobius[1] = 1;
    
  for(int i=2;i<N;i++)
  {
      if(lastprime[i] == -1) mobius[i] = -1;
      else if( (i/lastprime[i]) % lastprime[i] == 0) mobius[i] = 0;
      else mobius[i] = (mobius[lastprime[i]]*mobius[i/lastprime[i]]);
  }
}

void solve()
{
   int n;
    cin >> n;
    
   f(i,n) cin >> a[i];

   f(i,n) fre[a[i]]++;
    
   for(int i=1;i<N;i++)
       for(int j=i+i;j<N;j+=i) fre[i]+=fre[j];
    
   int res = 0;    
    
   for(int i=1;i<N;i++) fre[i] = mod_pow(2,fre[i]) - 1; 
   
   for(int i=1;i<N;i++)
   {
       if(mobius[i] == 0) continue;
       else if(mobius[i]== 1) res = (res + fre[i])%MOD;
       else res = (res + MOD - fre[i])%MOD;
   }
    
   
    cout << res ;
}

signed main()
{
    fast;
    
    sieve_mobius();
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}