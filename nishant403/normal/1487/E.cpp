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


const int N = 2e5 + 100;
const int inf = 1e17;

int cost[4][N];
vi go[4][N];
vector<int> cur(N),nex(N);

void solve()
{
   int n[4];
    f(i,4) cin >> n[i];
    
   f(i,4) f(j,n[i]) cin >> cost[i][j]; 

   int t,x,y;
    
   f(i,3) 
   {
       cin >> t;
       
       while(t--)
       {
           cin >> x >> y;
           x--,y--;
           go[i][y].pb(x);
       }
   }
    
   f(i,N) cur[i] = inf; 
   f(i,n[0]) cur[i] = cost[0][i]; 
    
   f(i,3)
   {
       f(j,N) nex[j] = inf;
       
       multiset<int> ms;
       f(j,n[i]) ms.insert(cur[j]);
      
       f(j,n[i+1])
       {
           for(auto z : go[i][j]) ms.erase(ms.find(cur[z]));
           if(!ms.empty()) nex[j] = cost[i+1][j] + *ms.begin();
           for(auto z : go[i][j]) ms.insert(cur[z]);
       }
       
       swap(cur,nex);
   }
   
   int res = *min_element(all(cur));
    if(res == inf) res = -1;
    
   cout << res; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}