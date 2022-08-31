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


void solve()
{
   int n;
   double k;
   cin >> n >> k;
    
   double a[n+2];
   for(int i=1;i<=n;i++) cin >> a[i];
   a[0] = 0;
   a[n+1] = k;
    
    double l = 0;
    double r = k;
    double res = k;
    
    f(i,100)
    {
        double mid = (l+r)/2;
        
        //check tot distance in time mid;
        
        double dis = 0.000000;
        double disa = 0.0000000;
        double disb = 0.0000000;
        
        double tma = mid;
        double tmb = mid;
        double vb = 1.00000000;
        double va = 1.000000000;
        
        for(int i=1;i<=n+1;i++)
        {
            double reachi = (a[i] - a[i-1])/va;
            
            if(tma >= reachi)
            {
                tma-=reachi;
                disa+=(a[i] - a[i-1]);
                va++;
            }
            else
            {
                disa+=(va*tma);
                break;
            }
        }
        
        for(int i=n;i>=0;i--)
        {
            double reachi = (a[i+1] - a[i])/vb;
            
            if(reachi <= tmb)
            {
                tmb-=reachi;
                disb+=(a[i+1] - a[i]);
                vb++;
            }
            else
            {
                disb+=(vb*tmb);
                break;
            }
        }
        
        if(disa + disb >= k)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << precise(6) << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}