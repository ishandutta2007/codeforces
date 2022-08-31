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

const int N = 1e5 + 10;


void solve()
{
   int n;
    cin >> n;
    
   string a,b;
    cin >> a >> b;
    
   vi res;
    
   int l = 0;
   int r = n-1;
   int rev = 0;   
    
   for(int i=n-1;i>=0;i--)
   {
       int id = l + i;
       
       if(rev) id = r - i;
       
       int bit = a[id] - '0';
       
       if(rev) bit^=1;
       
       if(bit == b[i] - '0') 
       {
           if(!rev) r--;
           else l++;
           
           continue;
       }
       
       int start = a[l] - '0';
       if(rev) start = a[r] - '0';
       if(rev) start^=1;
       
       if(start == b[i] - '0') res.pb(0);
       res.pb(i);
       
       if(rev) r--;
       else l++;
       
       rev^=1;
   }
    
   cout << res.size() << ' ';
    
   for(auto x : res) cout << x+1 << ' ';
    
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