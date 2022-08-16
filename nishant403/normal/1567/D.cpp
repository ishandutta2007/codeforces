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

const int N = 20;
int pw[N];

vi to_digit(int x)
{
    vi res;
    
    while(x > 0) {
        res.pb(x % 10);
        x /= 10;
    }
    
    return res;
}

void solve()
{
   int s,n;
   cin >> s >> n;
    
   vi ans(n,0);
    
   //what we need to do ? we need to utilize the potential each digit has
   //the highest digit has the best potential and we should make sure that its value is preserved
   //so the best case is, we can have all the digits in their proper position
   //if there remains 0s, then we can break the smallest number into 10 parts
    
   vi dg = to_digit(s);
    
   int itr = 0;
    
   f(i,dg.size()) f(j,dg[i])
   {
       ans[itr] += pw[i];
       itr = (itr + 1)%n;
   }
    
   while(1)
   {
       int flag = 0;
       for(auto x : ans) if(x == 0) flag = 1;
           
       if(flag == 1)
       {
           int mn = -1;
           
           f(i,n) if(ans[i] > 9)
           {
               if(mn == -1) mn = i;
               else if(ans[mn] > ans[i]) mn = i;
           }
               
           int val = ans[mn]/10;
           
           f(i,n)
           {
               if(ans[i] == 0 && ans[mn] > val)
               {
                   ans[i] += val;
                   ans[mn] -= val;
               }
           }
       }
       else break;
       
   }
           
   for(auto x : ans) cout << x << ' ';
   cout << '\n';
}

signed main()
{
    pw[0] = 1;
    for(int i=1;i<N;i++) pw[i] = (pw[i-1]*10);
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}