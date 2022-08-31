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
#define L(p) 2*p+1
#define R(p) 2*p+2

const int inf = 1e18;
const int N = 3e5+5;

  
struct node
{
    int np,pn,pp,nn;
    
    node() {}
};
node seg[4*N];
 
node fun(node &a,node &b)
{
    node ans;
    ans.pp = ans.pn = ans.np = ans.nn = -inf;
    
    ans.pp = max(a.pp,b.pp);
    ans.pp = max(ans.pp,a.pn + b.pp);
    ans.pp = max(ans.pp,a.pp + b.np);
    
    ans.pn = max(a.pn,b.pn);
    ans.pn = max(ans.pn,a.pn + b.pn);
    ans.pn = max(ans.pn,a.pp + b.nn);
    
    ans.np = max(a.np,b.np);
    ans.np = max(ans.np,a.np + b.np);
    ans.np = max(ans.np,a.nn + b.pp);
    
    ans.nn = max(a.nn,b.nn);
    ans.nn = max(ans.nn,a.np + b.nn);
    ans.nn = max(ans.nn,a.nn + b.pn);
    
    return ans;
}
 
void update(int l ,int h , int p, int ql, int qh,int v)
{
    if(l > qh || h < ql) return;
    
    else if(l >= ql && h <= qh)
    {
        seg[p].pp = v;
        seg[p].nn = -v;
        seg[p].np = -inf;
        seg[p].pn = -inf;
        return;
    }
    
    int m = (l + h )>> 1;
    update( l , m , L(p) ,ql ,qh,v);
    update(m+1 , h , R(p) , ql ,qh,v);
    seg[p] = fun(seg[L(p)],seg[R(p)]);
    return;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    
    for(int i=0;i<4*n;i++) seg[i].pp = seg[i].pn = seg[i].np = seg[i].nn = -inf;
    
    int a[n];
    f(i,n) cin >> a[i];
    f(i,n) update(0,n-1,0,i,i,a[i]);
    
    cout << seg[0].pp << '\n';  
    
    while(k--)
    {
        int l,r;
        cin >> l >> r;
        l--; r--;
        
        int al = a[l];
        int ar = a[r];
        swap(a[l],a[r]);
        
        update(0,n-1,0,l,l,ar);
        update(0,n-1,0,r,r,al);
        cout << seg[0].pp << '\n';
    }
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}