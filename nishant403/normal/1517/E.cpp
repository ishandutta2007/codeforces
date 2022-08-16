#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
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

const int MOD = 998244353;

//in a sorted array c
//how many integers from index l to r are <= k
int calc(vector<int> & c,int l,int r,int k)
{
    int res = 0;
    
    res += upper_bound(c.begin() + l,c.end(),k) - (c.begin() + l);
    
    return res;
}

int solve(vector<int> & b ,int lim)
{
    int n = b.size();
    int res = 0;
    
    int sum = 0;
    
    vector<int> od, ev;
    
    for(int i=0;i<n;i++)
    {
        if(i % 2 == 0) ev.pb(b[i]);
        else od.pb(b[i]);
    }
    
    for(int i=1;i<od.size();i++) od[i] += od[i-1];
    for(int i=1;i<ev.size();i++) ev[i] += ev[i-1];
    
    //case 1 : only take consecutive elements
    for(int i=0;i<n;i++)
    {
        sum += b[i];
        if(sum <= lim) res++;
    }
    
    //case 2 : also take elements at distance 2
    sum = 0;
    
    for(int i=0;i<n-2;i++)
    {
        sum += b[i];
        
        //we took consecutive elements upto i
        //now we take elemets b[i+2] , b[i+4] , .. upto total sum <= lim
        if(i % 2 == 0)
        {
            res += calc(ev,(i/2) + 1,(int)ev.size() - 1,lim - sum + ev[i/2]);
        }
        else
        {
            res += calc(od,(i/2) + 1,(int)od.size() - 1,lim - sum + od[i/2]);
        }
    }
    
    return res;
}

void solve()
{
   int n;
   cin >> n;
    
   int a[n];
   f(i,n) cin >> a[i];
    
   int sum = 0;
   f(i,n) sum += a[i];
    
   //find all such arrays having their sum <= lim 
   int lim = (sum - 1)/2;
    
   int res = 1;
   
   //step 1 : take all suffixes starting from 2 or more
   sum = 0;
    
   for(int i=n-1;i>=0;i--)
   {
       sum += a[i];
       if(sum <= lim) res++;
   }
    
   //step 2 : all such arrays starting from 0 or 1
   //also consider if end is taken or not
   for(int start=0;start<=1;start++)
     for(int end=0;end<=1;end++)  
   {
       vector<int> b;
       
       for(int i=start;i<n-1-end;i++) b.pb(a[i]);
       
       res += solve(b,lim - (end*a[n-1]));
   }
    
   res %= MOD;
   
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