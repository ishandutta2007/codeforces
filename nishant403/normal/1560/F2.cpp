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

vector<int> go[3];

int create(int n,int v,int z)
{
    f(i,z) n = (n*10) + v;
    return n;
}


int get(int x)
{
    vi fre(10,0);
    int res = 0;
    
    while(x > 0)
    {
        fre[x % 10]++;
        x /= 10;
    }
    
    f(i,10) if(fre[i] > 0) res++;
        
    return res;
}


void solve()
{
   int n,k;
    cin >> n >> k;
    
   if(get(n) <= k)
   {
       cout << n << '\n';
       return;
   }
    
   vector<int> dg;
    
   while(n > 0)
   {
       dg.pb(n % 10);
       n/=10;
   }
    
   reverse(all(dg));
    
   int num = 0;
    
   f(i,dg.size())
   {
       if(dg[0] == 9) num = (num*10) + 9;
       else num = (num*10) + (dg[0] + 1);
   }
    
   vector<int> fre(10,0);
   int nn = 0; 
    
   for(int i=1;i<dg.size();i++)
   {
       nn = create(nn,dg[i-1],1);
       
       for(int j=dg[i]+1;j<=9;j++)
       {
           for(int v=0;v<9;v++)
           {
               int new_num = create(create(nn,j,1),v,(int)dg.size()-i-1);
               if(get(new_num) <= k) num = min(num,new_num);
           }
       }
   }
    
   cout << num << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}