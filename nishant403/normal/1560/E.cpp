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


bool valid(string & s,string & t,string & rem)
{
    string T = "";
    
    vector<bool> invalid(26,0);
    
    for(auto x : rem)
    {
        for(auto y : s) if(invalid[y - 'a'] == 0) T += y;
        invalid[x - 'a'] = 1;
    }
    
    return (t == T);
}

void solve()
{
   string t;
   cin >> t;
    
   int n = t.length();
    
   vi fre(26,0); 
   
   string rem;
    
   for(int i=n-1;i>=0;i--)
   {
       if(fre[t[i] - 'a'] == 0) rem += t[i];
       fre[t[i] - 'a']++;
   }
    
   vector<int> ori_fre(26,0);
    
   reverse(all(rem)); 
   int len = 0;
    
   f(i,rem.length())
   {
       ori_fre[rem[i] - 'a'] = fre[rem[i] - 'a']/(i + 1);
       len += ori_fre[rem[i] - 'a'];
   }

   string s = t.substr(0,len);
    
   if(valid(s,t,rem))
   {
       cout << s << ' ' << rem << '\n';
       return;
   }
   else cout << -1 << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}