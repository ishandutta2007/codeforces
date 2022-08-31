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

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e6+10;
int n;
int a[N];
double arr[N];

struct item
{
    int l,r;
    double val;
    
    item() {}
    
    item(int id,double avg)
    {
       l = r = id;
       val = avg;
    }
};

item merge(item & a,item & b)
{
   item c;
   c.l = a.l;
   c.r = b.r;
   c.val = ((a.r-a.l+1)*a.val);
   c.val+= ((b.r-b.l+1)*b.val);
   c.val/=(b.r-a.l+1);
   return c;
}

void solve()
{
   cin >> n;
    
   f(i,n) cin >> a[i];
   f(i,n) arr[i] = a[i]; 
    
   int l = 0;
    
   stack<item> st; 
    
   for(int i=n-1;i>=0;i--)
   {
       item neww(i,arr[i]);
      
       while((!st.empty()) && (st.top().val) < neww.val) 
       {
           auto x = st.top(); st.pop();
           neww = (merge(neww,x));
       }
       
       st.push(neww);
   }
   
   while(!st.empty())
   {
       auto x = st.top(); st.pop();
       for(int i=x.l;i<=x.r;i++) arr[i] = x.val;
   }
    
   cout << precise(9);
    
   f(i,n) cout << arr[i] << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}