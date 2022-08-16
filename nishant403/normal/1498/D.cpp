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
vi cur(N);
int res[N];

const int M = 1e5;

void solve()
{
   int n,m;
   cin >> n >> m;
    
   for(int i=1;i<=m;i++) res[i] = -1; 
    
   cur[0] = 1;
    
   int x,y,t;
    
   for(int j=1;j<=n;j++) 
   {
       cin >> t >> x >> y;
       
       for(int i=m;i>=0;i--)
       {
           int take = i;
           int op = 0;
           
           while(take <= m && cur[take] == 1 && op < y)
           {

               int lst = take;

               if(t == 1) take = (take + (x + M - 1)/M);
               else take = ((take*x) + M - 1)/M;
               
               if(take == lst) break;
               
               if(take > m ) break;
               
               if(cur[take] == 1) break;
               
               res[take] = j;    
               cur[take] = 1;
               op++;
           }
       }
       
   }
   
   for(int i=1;i<=m;i++)
       cout << res[i] << ' ';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}