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

const int N = 4e5 + 10;
pii seg[4*N];
pii lazy[4*N];

//first : mask
//second : product

int a[N];

vector<int> pr;
vector<int> inv;

int mask[N];

void push(int node,int ss,int se)
{
    if(lazy[node].F > 0)
    {
        seg[node].F |= lazy[node].F;
        
        if(ss != se)
        {
            lazy[node*2+1].F |= lazy[node].F;
            lazy[node*2+2].F |= lazy[node].F;
        }
        
        lazy[node].F = 0;
    }
    
    if(lazy[node].S != 1)
    {
        seg[node].S *= mod_pow(lazy[node].S,se-ss+1);
        seg[node].S %= MOD;
        
        if(ss != se)
        {
            lazy[node*2+1].S *= lazy[node].S;
            lazy[node*2+2].S *= lazy[node].S;
            lazy[node*2+1].S %= MOD;
            lazy[node*2+2].S %= MOD;
        }
        
        lazy[node].S = 1;
    }
}

void update(int node,int ss,int se,int l,int r,int x)
{
    push(node,ss,se);
    
    if(se < l || ss > r) return;
    
    if(l <= ss && se <= r)
    {
        lazy[node].F |= mask[x];
        lazy[node].S *= x;
        lazy[node].S %= MOD;
        
        push(node,ss,se);
        
        return;
    }
    
    int mid = (ss + se)/2;
    
    update(node*2+1,ss,mid,l,r,x);
    update(node*2+2,mid+1,se,l,r,x);
    
    seg[node].F = seg[node*2+1].F | seg[node*2+2].F;
    seg[node].S = (seg[node*2+1].S*seg[node*2+2].S)%MOD;
}

pair<int,int> query(int node,int ss,int se,int l,int r)
{
    push(node,ss,se);
    
    if(se < l || ss > r) return {0,1};
    
    if(l <= ss && se <= r) return seg[node];
    
    int mid = (ss + se)/2;
    
    pii q1 = query(node*2+1,ss,mid,l,r);
    pii q2 = query(node*2+2,mid+1,se,l,r);
    
    return {q1.F|q2.F,(q1.S*q2.S)%MOD};
}

void solve()
{
    f(i,4*N) seg[i] = {0,1};
    f(i,4*N) lazy[i] = {0,1};
    
    int n,q;
    cin >> n >> q;
    
    f(i,n) cin >> a[i];
    f(i,n) update(0,0,n-1,i,i,a[i]);
    
    string s;
    int x,y,z;
    
    while(q--)
    {
        cin >> s;
        
        if(s[0] == 'M')
        {
            cin >> x >> y >> z;
            x--,y--;
            
            update(0,0,n-1,x,y,z);
        }
        else
        {
            cin >> x >> y;
            x--,y--;
            
            pii go = query(0,0,n-1,x,y);
            
            int res = go.S;
            
            f(j,pr.size())
                if((go.F >> j) & 1) res = (res*inv[j])%MOD;
                
            cout << res << '\n';
        }
    }
}

signed main()
{
    for(int i=2;i<=300;i++)
    {
        int flag = 1;
        
        for(int j=2;j<i;j++)
            if(i % j == 0) flag = 0;
    
        if(flag == 1) pr.pb(i);
    }
    
    for(int i=1;i<=300;i++)
        for(int j=0;j<pr.size();j++)
            if(i % pr[j] == 0) mask[i] |= (1LL<<j);
    
    for(auto x : pr)
    {
        int num = mod_pow(x,MOD-2);
        
        num = (MOD - num)%MOD;
        num = (num + 1)%MOD;
        
        inv.pb(num);
    }
        
    fast;
    solve();
}