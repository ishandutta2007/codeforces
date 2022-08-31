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

const int N = 4e5 + 100; 
pii init = {N,N};
int n;
vector<pii> st(2*N,init);
 
pii fun(pii a,pii b)
{
 return min(a,b);   
}
 
void update(int id,pii val)
{
    id+=n;
    st[id] = fun(st[id],val);
    
  for(;id>1;id>>=1)
      st[id>>1] =fun( st[id],st[id^1] );
}
 
pii query(int l,int r)
{
    pii res = init;
    
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1)
    {
     if(l&1) res=fun(res,st[l++]);
     if(r&1) res=fun(res,st[--r]);   
    }
    
    return res;
}

void solve()
{
    cin >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
    
   vi vals;
    f(i,n) vals.pb(a[i].F),vals.pb(a[i].S);
    sort(vals.begin(),vals.end());
    f(i,n) a[i].F = lower_bound(vals.begin(),vals.end(),a[i].F)-vals.begin();
    f(i,n) a[i].S = lower_bound(vals.begin(),vals.end(),a[i].S)-vals.begin();
     
   pii b[n],c[n];
    f(i,n) b[i] = a[i], c[i] = {a[i].S,a[i].F};
   
    int nn = n;
    n+=n;
   
    f(i,n+n) st[i] = init;
    f(i,nn) update(b[i].F,{b[i].S,i});
    f(i,nn) update(c[i].F,{c[i].S,i});
     
    f(i,nn)
    {
        pii gg = query(0,a[i].F-1);
        
        if(gg.F < a[i].S)
        {
            cout << gg.S + 1 << ' ';
        }
        else cout << -1 << ' ';
    }
    cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}