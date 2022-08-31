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

const int N = 2e5+10;
pii seg[4*N];

void upd(int node,int ss,int se,int id,int val)
{
    if(ss > id || se < id) return;
    
    if(ss == id && se == id)
    {
        seg[node].F++;
        seg[node].S+=val;
        return;
    }
    
    int mid = (ss+se)/2;
    
    upd(node*2+1,ss,mid,id,val);
    upd(node*2+2,mid+1,se,id,val);
    
    seg[node].F = seg[node*2+1].F + seg[node*2+2].F;
    seg[node].S = seg[node*2+1].S + seg[node*2+2].S;    
}

pii query(int node,int ss,int se,int l,int r)
{
    if(ss > r || se < l) return {0,0};
    
    if(l <= ss && se <= r) return seg[node];
    
    int mid = (ss+se)/2;
    
    pii a = query(node*2+1,ss,mid,l,r);
    pii b = query(node*2+2,mid+1,se,l,r);
    
    return {a.F+b.F,a.S+b.S};
}

vector<pii> compress(vector<pii> & a)
{
    int n = a.size();
    vector<pii> b(n);
    f(i,n) b[i].F = a[i].F,b[i].S = i;
    
    sort(b.begin(),b.end());
    f(i,n) a[b[i].S].F = i;
  
    return b;
}

void solve()
{
   int n;
   cin >> n;
    
   vector<pii> a(n);
   
   f(i,n) cin >> a[i].F;
   f(i,n) cin >> a[i].S;
    
   auto vv = compress(a); 
    
   f(i,n) swap(a[i].F,a[i].S);
   sort(a.begin(),a.end());
   reverse(a.begin(),a.end());
   f(i,n) swap(a[i].F,a[i].S);
   
   int res = 0;
    
   f(i,n)
   {
       auto xx =query(0,0,n-1,a[i].F,n-1);
       res+=xx.S-(xx.F*vv[a[i].F].F);
       upd(0,0,n-1,a[i].F,vv[a[i].F].F);
   }
    
   cout << res;
}

signed main()
{
    fast;
    solve();
}