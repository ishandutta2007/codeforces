#include <bits/stdc++.h>
using namespace std;
  
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


void solve()
{
   int n;
    cin >> n;
    
   set<pii> st;
    
   int a[n];
    
    st.insert({-n,0}); 
    
   f(i,n)
   {
       auto v = *st.begin();
       st.erase(st.begin());
       
       int l = v.S;
       int r = v.S - v.F - 1;
       
       int id;
       
       if((r-l+1)%2 == 0)
       {
           id = (l+r-1)/2;
       }
       else id = (l+r)/2;
       
       a[id] = i+1;
       
       if(l < id)
           st.insert({-(id-l),l});
       
       if(id < r)
           st.insert({-(r-id),id+1});
   }
    
   f(i,n) cout << a[i] << ' ';
    cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}