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

const int N = 1e3 + 10;
string s[N];

void solve()
{
   int n,m;
    cin >> n >> m;
    
   f(i,n) cin >> s[i];
    
   if(m % 2 == 1)
   {
       cout <<"YES\n";
       
       f(i,m+1) 
           cout << ((i % 2) + 1) << ' ';
       
       cout << '\n';
       
       return;
   }
    
   f(i,n)
       f(j,n)
   {
       if(s[i][j] != '*' && s[i][j] == s[j][i])
       {
           cout <<"YES\n";
           
           f(v,m+1)
               if(v % 2 == 0) cout << i + 1<< ' ';
               else cout << j + 1 << ' ';
               
           cout << '\n';
           return;
       }
   }
    
   f(i,n) 
   {
       int la = -1 , lb = -1;
       
       f(j,n)
           if(s[i][j] == 'a')
       {
           if(lb != -1)
           {
               cout <<"YES\n";
            
               int hlf = (m/2) - 1;
            
               f(v,hlf)
               {
                   if(hlf % 2 == 0)
                   {
                       if(v % 2 == 0) cout << j + 1 << ' ';
                       else cout << i + 1 << ' ';
                   }
                   else 
                   {
                       if(v % 2 == 1) cout << j + 1 << ' ';
                       else cout << i + 1 << ' ';
                   }
               }
               
               cout << j + 1 << ' ' << i + 1 << ' ' << lb + 1 << ' ';
               
               f(v,hlf)
               {
                       if(v % 2 == 1) cout << lb + 1 << ' ';
                       else cout << i + 1 << ' ';
               }
                   
               cout << '\n';
               return;
           }
               
           la = j;
       }
       else if(s[i][j] == 'b')
       {
           if(la != -1)
           {
               cout <<"YES\n";
            
               int hlf = (m/2) - 1;
               
               f(v,hlf)
               {
                   if(hlf % 2 == 0)
                   {
                       if(v % 2 == 0) cout << j + 1 << ' ';
                       else cout << i + 1 << ' ';
                   }
                   else 
                   {
                       if(v % 2 == 1) cout << j + 1 << ' ';
                       else cout << i + 1 << ' ';
                   }
               }
               
               cout << j + 1 << ' ' << i + 1 << ' ' << la + 1 << ' ';
               
               
               f(v,hlf)
               {
                       if(v % 2 == 1) cout << la + 1 << ' ';
                       else cout << i + 1 << ' ';
               }
                   
               cout << '\n';
               return;
           }
           
           lb = j;
       }
   }
    
   cout << "NO\n";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}