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


void solve()
{
  int n;
  cin >> n;
    
  string s;
  cin >> s;
    
  int col[n];
  col[0] = 1;
   
  vi pg(n,-1);  
    
  stack<int> st;
    
  for(int i=n-1;i>=0;i--)
  {
      while(!st.empty() && s[i] > s[st.top()])
      {
          auto x = st.top(); st.pop();
          pg[x] = i;
      }
      
      st.push(i);
  }
  
    
  vi co(26,0);
  co[s[0]-'a'] = 1;
    
  for(int i=1;i<n;i++)
  {
      if(pg[i] == -1) col[i] = 1;
      else
      {
          int mx = 0;
          for(int j = (s[i]-'a')+1;j<26;j++)
              mx=max(mx,co[j]);
          col[i] = mx + 1;
      }
      
      co[s[i]-'a'] = col[i];
  }
   
    int res = 0;
    f(i,n) res=max(res,col[i]);
    
    cout << res << '\n';
    f(i,n) cout << col[i] << " ";
     
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}