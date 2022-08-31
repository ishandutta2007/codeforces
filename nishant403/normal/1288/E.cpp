#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 3e5+10;
vi g[N];
pii ans[N];
int a[N],n,m;

struct node
{
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}
};

node* null = new node(0,NULL,NULL);
node* nodes[N];

node* insert(node* old,int l,int r,int val)
{
    if(l > val || r < val) return old;
     
    if(l==r) return new node(1,null,null);
   
    int mid = (l+r)/2;
    
    return new node(old->count+1,insert(old->left,l,mid,val),insert(old->right,mid+1,r,val));
}

int query(node* a,int l,int r,int k)
{
 if(l > k) return 0;  
 if(r <= k) return a->count;   
    
 int mid = (l+r)/2;
    
 return query(a->left,l,mid,k) + query(a->right,mid+1,r,k);
}

void build()
{
    null->left = null->right = null;
    
    vector<int> A(m);
    
    f(i,n)
    {
        if(g[i].empty()) continue;
        for(int j=1;j<g[i].size();j++) A[g[i][j-1]]=g[i][j];
        A[g[i].back()]=m;
    }
    
    nodes[0] = insert(null,0,m,A[0]);
            
    for(int i=1;i<m;i++)
        nodes[i] = insert(nodes[i-1],0,m,A[i]);
}

int query(int l,int r)
{
    int res = query(nodes[r],0,m,r);
    if(l>0) res-=query(nodes[l-1],0,m,r);
    return (r-l+1) - res;
}

void solve()
{
  cin >> n >> m;
    
  f(i,m) cin >> a[i];
  f(i,m) g[a[i]].pb(i-1);
  
  f(i,n) if(g[i].empty()) ans[i].F = i;
         else ans[i].F = 1;
   
  f(i,n) ans[i].S = i;  
      
  vector<bool> used(n+1,0);    
  ordered_set os;  
    
  f(i,m) 
  if(used[a[i]] == 0)
  {
      ans[a[i]].S += (int)os.size() - os.order_of_key(a[i]);
      used[a[i]] = 1;
      os.insert(a[i]);
  }
   
  f(i,n) if(g[i].empty()) ans[i].S+=(int)os.size() - os.order_of_key(i);  
   
  build();   
      
  f(i,n)   
  {
      if(g[i].empty()) continue;
      for(int j=1;j<g[i].size();j++)
      {
        ans[i].S = max(ans[i].S,1+query(g[i][j-1]+1,g[i][j]-1));
      }
    
      ans[i].S = max(ans[i].S,1+query(g[i].back()+1,m-1));
  }
    
   f(i,n) cout << ans[i].F <<" "<<ans[i].S << '\n'; 
    
}

signed main()
{
    fast;
    solve();
}