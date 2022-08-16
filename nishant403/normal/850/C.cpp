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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


const int SZ = 31;

int get_red(int mask,int red)
{
    int new_mask = 0;
    
    for(int j=0;j<SZ;j++)
    {
        if((mask >> j) & 1)
        {
            if(j < red - 1)
            {
                new_mask |= (1LL<<j);
            }
            else if(j == red - 1) ;
            else
            {
                new_mask |= (1LL<<(j - red));
            }
        }
    }
    
    return new_mask;
}

map<int,int> mp2;

int solve(int x)
{
    if(mp2.find(x) != mp2.end()) return mp2[x];
    
    set<int> st;
   
    for(int j=0;j<=SZ+5;j++) st.insert(j); 
       
    for(int j=1;j<=SZ;j++)
    {
       int cc = get_red(x,j);
           
       if(cc != x) st.erase(solve(cc)); 
    }
       
    return mp2[x] = (*st.begin());
}

map<int,set<int> > mp;

//check if game on this set is winning or losing state
int go(set<int> st)
{
    int msk = 0;
    
    for(auto x : st)
        msk |= 1LL<<(x - 1);
    
    return solve(msk);
}

void solve()
{
   int n;
    cin >> n;
    
  f(i,n)
  {
      int x;
      cin >> x;
      
      for(int j=2;(j*j)<=x;j++)
      {
          int cc = 0;
          
          while(x % j == 0)
          {
              cc++;
              x/=j;
          }
          
          if(cc > 0) mp[j].insert(cc);
      }
      
      if(x > 1) mp[x].insert(1);
  }
    
  int res = 0;
    
  for(auto x : mp) res ^= go(x.S);
    
  if(res == 0) cout <<"Arpa";
  else cout << "Mojtaba";    
}

signed main()
{
    fast;
    solve();
}