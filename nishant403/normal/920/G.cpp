#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 1e6 + 10;

vector<int> lastprime(N,-1);
vector<int> factors[N];

void sieve_lastprime()
{
  lastprime[0] = lastprime [1] = 0;
    
  //-1 is prime
    
  for(int i=2;i<N;i++)
  {
    if(lastprime[i] == -1)
    {
        for(int j=i*i;j<N;j+=i) 
            lastprime[j] = i;  
        
        for(int j=i;j<N;j+=i) factors[j].push_back(i);
    }
  }
}

vector<int> phi(N);

void sieve_phi()
{
    for(int i=0;i<N;i++) phi[i] = i;
    
    for(int i=2;i<N;i++)
    {
      if(phi[i] == i)
          for(int j=i;j<N;j+=i)
             phi[j] -= (phi[j]/i);
    }
}

//find number of coprimes of p which are <= x using inclusion exclusion
int get2(int p,int x)
{
    int cnt = 0;
    
    int sz = factors[p].size();
    
    f(i,(1LL<<sz))
    {
        int num = 1;
        
        f(j,sz)
            if((i>>j) & 1) num *= factors[p][j];
        
        int vals = (x / num);
        
        if(__builtin_popcount(i) & 1) cnt -= vals;
        else cnt += vals;
    }
        
    return cnt;
}

//find number of coprimes of p which are <= x
int get(int p,int x)
{
    int res = 0;
    
    int full = (x / p);
    
    res += full*phi[p];

    int partial = (x % p);

    res += get2(p,partial);
        
    return res;  
}

void solve()
{
   int x,p,k;
    cin >> x >> p >> k;
    
   int coprimes_upto_x = get(p,x);
    
   k += coprimes_upto_x;
    
   int l = 1;
   int r = 1e9;
   int res = r;
    
   vector<int> add,rem;
   
   int sz = factors[p].size();
   
   f(i,(1<<sz))
   {
       int num = 1;
       
       f(j,sz)
        if((i >> j) & 1) num *= factors[p][j];
        
      if(__builtin_popcount(i) & 1) rem.pb(num);
      else add.pb(num);
   }
   
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       int cnt = 0;
       
       cnt += phi[p]*(mid / p);
       int partial = (mid % p);
       
       for(auto x : add) cnt += (partial / x);
       for(auto x : rem) cnt -= (partial / x);
       
       if(cnt >= k)
       {
           res = mid;
           r = mid - 1;
       }
       else l = mid + 1;
   }
    
   cout << res << '\n'; 
}

signed main()
{
    sieve_phi();
    sieve_lastprime();

    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}