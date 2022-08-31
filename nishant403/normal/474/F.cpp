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

pii seg[4*N];
int a[N];

pii merge(pii x,pii y)
{
    int gc = __gcd(x.F,y.F);
    int cnt = 0;
    
    if(x.F == gc) cnt += x.S;
    if(y.F == gc) cnt += y.S;
    
    return {gc,cnt};
}

void build(int node,int ss,int se)
{
    if(ss == se)
    {
        seg[node] = {a[ss] , 1};
        return;
    }
    
    int mid = (ss + se)/2;
    
    build(node*2+1,ss,mid);
    build(node*2+2,mid+1,se);
    
    seg[node] = merge(seg[node*2+1],seg[node*2+2]);
}

pii query(int node,int ss,int se,int l,int r)
{
    if(ss > r || se < l) return {0,0};
    
    if(l <= ss && se <= r)
    {
        return seg[node];
    }
    
    int mid = (ss + se)/2;
    
    return merge(query(node*2+1,ss,mid,l,r) , query(node*2+2,mid+1,se,l,r));
}


void solve()
{
    int n;
   cin >> n;
    
    f(i,n) cin >> a[i];
    build(0,0,n-1);
    
    int q;
    cin >> q;
    
    while(q--)
    { 
        int l,r;
        cin >> l >> r;
        l--,r--;
        
        cout << (r-l+1) - query(0,0,n-1,l,r).S << '\n';
    }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}