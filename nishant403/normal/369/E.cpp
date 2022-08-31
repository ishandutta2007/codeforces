#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 3e5+10;
vi seg[4*N];
pii tag[4*N];
pii a[N];
int n,m,x;

void build(int node,int ss,int se)
{
    if(ss == se)
    {
        tag[node].F = tag[node].S = a[ss].F;
        seg[node].pb(a[ss].S);
        return;
    }
    
    int mid = (ss + se)/2;
    
    build(node*2+1,ss,mid);
    build(node*2+2,mid+1,se);
    
    tag[node].F = tag[node*2+1].F;
    tag[node].S = tag[node*2+2].S;
    
    merge(all(seg[node*2+1]),all(seg[node*2+2]),back_inserter(seg[node])); 
}

int query(int node,int ss,int se,int L,int R)
{
    if(tag[node].F > L) return 0;
    
    //number of values greater or equal to R.
    if(tag[node].S <= L)
        return (se-ss+1) - (lower_bound(all(seg[node]),R)-seg[node].begin());
    
    int mid = (ss+se)/2;
    
    return query(node*2+1,ss,mid,L,R) + query(node*2+2,mid+1,se,L,R);
}

int go(int l,int r)
{
   return query(0,0,n-1,l,r);
}

void solve()
{     
   cin >> n >> m;
   f(i,n) cin >> a[i].F >> a[i].S;
    
   sort(a,a+n); 
   build(0,0,n-1);
    
   while(m--)
   {
       int sz;
       cin >> sz;
       
       vi pt(sz);
       
       f(i,sz) cin >> pt[i];
       sort(all(pt));
       
       int res = go(pt[0],pt[0]);
       
       for(int i=1;i<sz;i++) res+=go(pt[i],pt[i]) - go(pt[i-1],pt[i]);
       
       cout << res << '\n';
   }
}

signed main()
{
    fast;
    solve();
}