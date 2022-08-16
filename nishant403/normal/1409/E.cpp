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
int n;
int a[N];
 
const int init = 0;
 
vector<int> st(2*N,init);
 
int fun(int a,int b)
{
 return max(a,b);   
}
 
void update(int id,int val)
{
  for(st[id+=n]=val;id>1;id>>=1)
      st[id>>1] =fun( st[id],st[id^1] );
}
 
int query(int l,int r)
{
    r++;
    
    int res = init;
    
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
     if(l&1) res=fun(res,st[l++]);
     if(r&1) res=fun(res,st[--r]);   
    }
    
    return res;
}

void solve()
{
   int k;
   cin >> n >> k;
    
    f(i,n) cin >> a[i];
  
   sort(a,a+n); 
   
   f(i,2*n) st[i] = 0;  
    
   int v;
    f(i,n) cin >> v;
    
   int res = 0; 
    
   for(int i=0;i<n;i++) 
   {
       //number of points between a[i] and a[i] - k
       int num = upper_bound(a,a+n,a[i]) - upper_bound(a,a+n,a[i]-k-1);
       
       //the point before a[i] - k
       int id = upper_bound(a,a+n,a[i]-k-1) - a - 1;
       
       if(id >= 0) res = max(res, num + query(0,id));
       else res = max(res,num);
       
       update(i,num);
   }
    
   cout << res << '\n'; 
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}