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

void solve()
{
   int n,k;
    cin >> n >> k;
    
   cout << *lower_bound(all(go[k]),n) << '\n';
}

signed main()
{
    for(int j=1;j<=9;j++)
    {
        int num = 0;
         
        for(int i=1;i<=11;i++)
        {
            num*=10;
            num+=j;
            go[1].pb(num);
        }
    }
    
    for(int i=1;i<=11;i++)
    {
        for(int j=0;j<(1LL<<i);j++)
        {
            vector<int> bts;
            
            f(v,i) bts.pb((j>>v) & 1);
            
            f(a1,10) f(a2,10)
            {
                if(bts[0] == 0 && a1 == 0) continue;
                
                int num = 0;
                
                f(v,i)
                {
                    if(bts[v] == 0) num = (num*10) + a1;
                    else num = (num*10) + a2;
                }
                
                go[2].pb(num);
            }
        }
    }
    
    sort(all(go[1]));
    sort(all(go[2]));
    
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}