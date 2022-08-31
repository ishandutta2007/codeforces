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

const int N = 1e5+10;
int seg[2*N];
int store[N];
int n,k;
const int NN = 1e5+2;

void upd(int id,int val)
{
    for(seg[id+=NN]+=val;id>1;id>>=1)
        seg[id>>1] = seg[id] + seg[id^1];
}

int query(int l,int r)
{
    int res = 0;
    
    for(l+=NN,r+=NN+1;l<r;l>>=1,r>>=1)
    {
        if(l&1) res+=seg[l++];
        if(r&1) res+=seg[--r];
    }
    
    return res;
}

void solve()
{
   cin >> n >> k;
    
   int a[n];
   f(i,n) cin >> a[i];
    
   int b[n];
   f(i,n) b[i] = a[i];
   sort(b,b+n);
    
   f(i,n) store[i] = 1;
    
   f(ggg,k)
   {
       f(i,n) 
       {
           upd(a[i],store[i]);
           store[i] = query(0,a[i]-1);
       }
       
       memset(seg,0,sizeof(seg));
   }
    
   int res = 0;
   f(i,n) res+=store[i];
   cout << res;
}

signed main()
{
    fast;
    solve();
}