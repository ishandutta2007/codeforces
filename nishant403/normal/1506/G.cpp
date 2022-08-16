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

string solve(string & s)
{
    if(s.length() <= 1) return s;
    
    //find largest character after which we still have enough characters
    int mask = 0;
    
    for(auto x : s) mask |= (1LL<<(x - 'a'));
    
    int temp = 0;
    int n = s.length();
    int pos = -1;
    
    for(int i=n-1;i>=0;i--)
    {
        temp |= (1LL<<(s[i] - 'a'));
        
        if(temp == mask)
        {
            if(pos == -1) pos = i;
            else if(s[i] >= s[pos]) pos = i;
        }
    }
    
    string tn ;
    
    for(int j=pos+1;j<n;j++)
      if(s[j] != s[pos]) tn += s[j];
        
    string ans = solve(tn);
   ans += s[pos];
    return ans;
}

void solve()
{
   string s;
   cin >> s;
    
    auto ans = solve(s);
    reverse(all(ans));
   cout << ans << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}