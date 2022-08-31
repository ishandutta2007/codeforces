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
#define all(x) x.begin(),x.end()

#define mat pair<pii,pii>

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int a[N];

mat seg[4*N];
mat lazy[4*N];

mat iden = {{1,0},{0,1}};
mat unit = {{1,1},{1,0}};
mat zr = {{0,0},{0,0}};

mat mult(mat p,mat q)
{
    mat r;
    
    r.F.F = p.F.F*q.F.F + p.F.S*q.S.F;
    r.F.S = p.F.F*q.F.S + p.F.S*q.S.S;
    r.S.F = p.S.F*q.F.F + p.S.S*q.S.F;
    r.S.S = p.S.F*q.F.S + p.S.S*q.S.S;
    
    r.F.F %= MOD;
    r.F.S %= MOD;
    r.S.F %= MOD;
    r.S.S %= MOD;
    
    return r;
}

mat add(mat p,mat q)
{
    p.F.F += q.F.F;
    p.F.S += q.F.S;
    p.S.F += q.S.F;
    p.S.S += q.S.S;
    
    p.F.F %= MOD;
    p.F.S %= MOD;
    p.S.F %= MOD;
    p.S.S %= MOD;
    
    return p;
}

void push(int node,int ss,int se)
{
    if(lazy[node] != iden)
    {
        seg[node] = mult(seg[node],lazy[node]);
        
        if(ss != se)
        {
            lazy[node*2+1] = mult(lazy[node*2+1],lazy[node]);
            lazy[node*2+2] = mult(lazy[node*2+2],lazy[node]);
        }
        
        lazy[node] = iden;
    }
}

void update(int node,int ss,int se,int l,int r,pair<pii,pii> x)
{
    push(node,ss,se);
    
    if(ss > r || se < l) return ;
   
    if(l <= ss && se <= r)
    {
        lazy[node] = mult(lazy[node],x);
        push(node,ss,se);
        return;
    }
    
    int mid = (ss + se)/2;
    
    update(node*2+1,ss,mid,l,r,x);
    update(node*2+2,mid+1,se,l,r,x);
    
    seg[node] = add(seg[node*2+1],seg[node*2+2]);
}

mat query(int node,int ss,int se,int l,int r)
{
    push(node,ss,se);
    
    if(ss > r || se < l) return zr;
   
    if(l <= ss && se <= r)
    {   
        return seg[node];
    }
    
    int mid = (ss + se)/2;
    
    return add(query(node*2+1,ss,mid,l,r),query(node*2+2,mid+1,se,l,r));
}

mat get_kth(int k)
{
    mat res = iden;
    mat aa = unit;
    
    while(k > 0)
    {
        if(k & 1) res = mult(res,aa);
        aa = mult(aa,aa);
        k >>=1;
    }
    
    return res;
}

void solve()
{
   int n,q;
   cin >> n >> q;
    
   f(i,n) cin >> a[i];
    
   f(i,4*N) seg[i] = lazy[i] = iden;
   f(i,n) update(0,0,n-1,i,i,get_kth(a[i]));
    
   int t,l,r,x; 
    
   while(q--)
   {
       cin >> t;
       
       if(t == 1)
       {
           cin >> l >> r >> x;
           l--,r--;
           update(0,0,n-1,l,r,get_kth(x));
       }
       else
       {
           cin >> l >> r;
           l--,r--;
           auto res = query(0,0,n-1,l,r);
           cout << res.S.F << '\n';
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