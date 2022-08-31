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

const int N = 2e6 + 10;
int a[N];
int fre[N];
int sum[N];

int n,x,y;

//g is the gcd we want
int go(int g)
{
    int res = 0;
    
    int keep = (x / y);
    
    //elements in range[max(i - g + 1 , i - keep) , i] to be either i or be deleted
    //from the cost of delete operation, we estimate what will be cheap
    for(int i=g;i<N;i+=g)
    {
        int L = max(i - g + 1 , i - keep);
        int R = i;
        
        int tot_cc = fre[i] - fre[i - g];
        int cc = fre[R] - fre[L - 1];
        int req_sum = sum[R] - sum[L - 1];
        
        res += ((cc*i) - (req_sum))*y;
        res += (tot_cc - cc)*x;
    }
    
    return res;
}

void solve()
{
    cin >> n >> x >> y;
    
    f(i,n) cin >> a[i];
    
    f(i,n) fre[a[i]]++;
    f(i,n) sum[a[i]] += a[i];
    
    for(int i=1;i<N;i++) fre[i] += fre[i-1];
    for(int i=1;i<N;i++) sum[i] += sum[i-1];
    
    int res = n*min(x,y);
    
    for(int i=2;i<N;i++) res = min(res,go(i));
    
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