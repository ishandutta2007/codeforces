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

void update(int node,int ss,int se,int id ,int val)
{
    if(ss == se)
    {
        seg[node] = {val,val};
        return;
    }
    
    int mid = (ss + se)/2;
    
    if(id <= mid) update(node*2+1,ss,mid,id,val);
    else update(node*2+2,mid+1,se,id,val);
    
    seg[node].F = seg[node*2+1].F + seg[node*2+2].F;
    seg[node].S = max(seg[node*2+1].S , seg[node*2+2].S);
}

void update2(int node,int ss,int se,int l,int r,int x)
{
    if(seg[node].S < x) return;
    if(se < l || ss > r) return;
    
    if(ss == se)
    {
        seg[node].F %= x;
        seg[node].S %= x;
        return;
    }
    
    int mid = (ss + se)/2;
    
    update2(node*2+1,ss,mid,l,r,x);
    update2(node*2+2,mid+1,se,l,r,x);
    
    
    seg[node].F = seg[node*2+1].F + seg[node*2+2].F;
    seg[node].S = max(seg[node*2+1].S , seg[node*2+2].S);
}

int query(int node,int ss,int se,int l,int r)
{
    if(se < l || ss > r) return 0;
    
    if(l <= ss && se <= r) return seg[node].F;
    
    int mid = (ss + se)/2;
    
    return query(node*2+1,ss,mid,l,r) + query(node*2+2,mid+1,se,l,r);
}

void solve()
{
   int n,q;
    cin >> n >>  q;
    
   int x;
    
   f(i,n)
   {
       cin >> x;
       update(0,0,n-1,i,x);
   }
    
   int t,l,r;
    
   while(q--)
   {
       cin >> t;
       
       if(t == 1)
       {
           cin >> l >> r;
           cout << query(0,0,n-1,l-1,r-1) << '\n';
       }
       else if(t == 2)
       {
           cin >> l >> r >> x;
           update2(0,0,n-1,l-1,r-1,x);
       }
       else
       {
           cin >> l >> x;
           update(0,0,n-1,l-1,x);
       }
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