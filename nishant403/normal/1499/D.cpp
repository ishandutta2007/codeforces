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

const int N = 2e7 + 10;
int cc[N];

void pre()
{
    for(int i=1;i<N;i++) cc[i] = 1;
    
    for(int i=2;i<N;i++)
    {
        if(cc[i] == 1)
            for(int j=i;j<N;j+=i) cc[j]<<=1;
    }
}

void solve()
{
   int c,d,x;
    cin >> c >> d >> x;
    
   int res = 0;
    
   for(int i=1;(i*i)<=x;i++)
   {
       if(x % i == 0)
       {
           int num = (x / i) + d;
           
           if(num % c == 0)
           {
               num/=c;
               res += cc[num];
           }
           
           if((i*i) != x)
           { 
               num = i + d;

               if(num % c == 0)
               {
                   num/=c;
                   res += cc[num];
               }
           }
       }
   }
    

   cout << res << '\n';
}

signed main()
{
    fast;
    
    pre();
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}