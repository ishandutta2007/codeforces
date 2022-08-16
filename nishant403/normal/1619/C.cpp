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


void solve()
{
   string a,s;
   cin >> a >> s;
    
   string b = ""; 
    
   //there is a unique digit in b,that can match a and s
   while(a.size() > 0 && s.size() > 0)
   {
       int dg = a.back() - '0';
       
       int flag = 0;
       
       f(i,10)
       {
           int ss = dg + i;
           
           if(ss <= 9)
           {
               if(s.back() - '0' == ss)
               {
                   b += i + '0';
                   s.pop_back();
                   a.pop_back();
                   flag = 1;
                   break;
               }
           }
           else if(s.length() > 1 && s.back() - '0' == (ss % 10) && s[(int)s.length() - 2] == '1')
           {
               b += i + '0';
               s.pop_back();
               s.pop_back(); 
               a.pop_back();
               flag = 1;
      
               break;
           }
       }
       
       if(flag == 0) break;
   }
    
   while(a.size() == 0 && s.size() > 0)
   {
       b += s.back();
       s.pop_back();
   }
    
   while(b.back() == '0') b.pop_back();
    
   reverse(all(b));
    
   if(s.size() == 0 && a.size() == 0)
   {
       cout << b << '\n';
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