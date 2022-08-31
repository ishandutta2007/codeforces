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

const int def = (1LL<<30)-1;
const int N = 1e5+10;
int seg[4*N];
int lazy[4*N];
int a[N];
 
void push(int node,int ss,int se)
{
    seg[node]|=lazy[node];
    
    if(ss != se) 
    {
        lazy[node*2+1]|=lazy[node];
        lazy[node*2+2]|=lazy[node];
    }
    
    lazy[node] = 0;
}
 
void update(int node,int ss,int se,int l,int r,int x)
{
    push(node,ss,se);
    
    if(ss > r || se < l) return;
    
    if(l <= ss && se <= r)
    {
        lazy[node]|=x;
        push(node,ss,se);
        return;
    }
    
    int mid = (ss+se)/2;
    
    update(node*2+1,ss,mid,l,r,x);
    update(node*2+2,mid+1,se,l,r,x);
    
    seg[node] = seg[node*2+1] & seg[node*2+2];
}
 
int query(int node,int ss,int se,int l,int r)
{
    push(node,ss,se);
    
    if(ss > r || se < l) return def;
    
    if(l <= ss && se <= r) return seg[node];
   
    int mid = (ss+se)/2;
    
    return query(node*2+1,ss,mid,l,r) & query(node*2+2,mid+1,se,l,r);
}

pair<pii,int> qu[N];

void solve()
{
   int n,q;
   cin >> n >> q;
    
   int flag = 1; 
    
   f(i,q) cin >> qu[i].F.F >> qu[i].F.S >> qu[i].S;
   f(i,q) qu[i].F.F--,qu[i].F.S--;
   f(i,q) update(0,0,n-1,qu[i].F.F,qu[i].F.S,qu[i].S);
   f(i,q) if(query(0,0,n-1,qu[i].F.F,qu[i].F.S) != qu[i].S) flag = 0;
    
   if(flag)
   {
       cout <<"YES\n";
       f(i,n) cout << query(0,0,n-1,i,i) <<" ";  
   }
   else cout <<"NO\n"; 
}

signed main()
{
    fast;
    solve();
}