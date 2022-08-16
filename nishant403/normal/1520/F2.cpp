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

const int N = 2e5 + 10;
const int BLK = 16;

int cc = 0;
 
int query(int l,int r)
{
   cout <<"? " << l << ' ' << r << endl;
   cc++;
   assert(cc <= 60000);
   cin >> l;
   return l;
}

int sum[N];

signed main()
{
    int n;
    int t = 1;
 
    cin >> n >> t;
 
    f(z,t)
    {
        //find block for that
        int l = 1;
        int r = n;
        int res = r;
        
        int k;
        cin >> k;
        
        if(z == 0)
        {
            for(int i=0;i<n;i+=BLK)
            {
                sum[i/BLK] = query(i + 1,min(n,i + BLK));

                int len = min(n,i + BLK) - i;

                sum[i/BLK] = len - sum[i/BLK];
            }
        }
        
        for(int i=0;i<n;i+=BLK)
        {
            if(sum[i/BLK] >= k)
            {
                l = i + 1;
                r = min(n,i + BLK);
                res = l;
                break;
            }
            else k -= sum[i/BLK];
        }
        
        int new_l = l;
            
        while(l <= r)
        {
            if(l == r)
            {
                res = r;
                break;
            }
            
            int mid = (l + r)/2;
            
            int zz = query(new_l,mid);
            
            int zrs = (mid - new_l + 1) - zz;
            
            if(zrs >= k)
            {
                r = mid; 
            }
            else
            {
                l = mid + 1;
            }
        }
    
        cout <<"! " << res << endl; 
        
        sum[(res - 1) / BLK]--;
    }
}