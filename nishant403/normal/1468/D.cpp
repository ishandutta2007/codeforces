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

const int N = 2e5 + 10;
int arr[N];
int n,m,a,b;

bool check(int x)
{
    for(int i=x-1;i>=0;i--)
    {
        int tm = arr[i] + x - i;
        if(tm >= b) return 0;
    }
    
    return 1;
}

void solve()
{
    cin >> n >> m >> a >> b;
    
    if(a > b) a = n + 1 - a , b = n + 1 - b;
    f(i,m) cin >> arr[i];
    sort(arr,arr+m);

    int l = 1;
    int r = min(m,b-a-1);
    int res = 0;
    
    while(l <= r)
    {
        int mid = (l+r)/2;
        
        if(check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    cout << res <<'\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}