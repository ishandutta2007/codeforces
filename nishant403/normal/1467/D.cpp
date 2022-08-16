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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        
        ret%=MOD;
        return ret;
    }

    int sum(int l, int r) {
        return ((sum(r) - sum(l - 1))%MOD + MOD)%MOD;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
        {
            bit[idx] += delta;
            bit[idx]%=MOD;
        }
    }
};

const int N = 5e3 + 10;
int dp[N][N];
int ways[N];
int a[N];
int n,k,q;

int calc(int x,int y)
{
    if(y == 0) return 1;
    
    int & res = dp[x][y];
    
    if(res != -1) return res;
    
    res = 0;
    
    if(x > 1) res = (res + calc(x-1,y-1))%MOD;
    if(x < n) res = (res + calc(x+1,y-1))%MOD;
    
    return res;
}

signed main()
{
    fast;
    
    cin >> n >> k >> q;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    
    memset(dp,-1,sizeof(dp));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++) 
            ways[i] += (calc(i,j)*calc(i,k-j))%MOD;

        ways[i]%=MOD;
    }
    
    int res = 0;
    for(int i=1;i<=n;i++) res+=(a[i]*ways[i])%MOD;
    res%=MOD;
   
    while(q--)
    {
        int x,y;
        cin >> x >> y;
     
        res-=(ways[x]*a[x])%MOD;
        a[x] = y;
        res+=(ways[x]*a[x])%MOD;
        
        res%=MOD;
        if(res < 0) res+=MOD;
        
        
        cout << res << '\n';
    }
}