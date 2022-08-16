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

const int N = 5e5+10;
int n,k,d;
int a[N];
int seg[2*N];
bool dp[N];

void upd(int id)
{
  for(seg[id+=n+1] = 1 ;id > 1;id>>=1) seg[id>>1] = seg[id] | seg[id^1];    
}

int query(int l,int r)
{
    int res = 0;
    
    for(l+=n+1,r+=n+2;l<r;l>>=1,r>>=1)
    {
        if(l&1) res|=seg[l++];
        if(r&1) res|=seg[--r];
    }
    
    return res;  
}

int bs(int id)
{
    int l = 1;
    int r = id;
    int res = id+1;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
        
        if(a[id] - a[mid] <= d)
        {
            res = min(res,mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    return res;
}

void solve()
{
   cin >> n >> k >> d;
    
   for(int i=1;i<=n;i++) cin >> a[i];
    
   sort(a+1,a+n+1);
    
   upd(0);   

   for(int i=1;i<=n;i++)
   {
       //first index in array which can be in same box.
       int id = bs(i);
       if(i-id+1 < k) continue;
       dp[i] = query(id-1,i-k);
       if(dp[i]) upd(i);
   }
    
   if(dp[n]) cout <<"YES\n";
   else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}