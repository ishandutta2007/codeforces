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
int go[N][5];

bool check(vi & a,vi & b)
{
    int rs = 0;
    
    f(j,5) rs += a[j]*b[j];
    
    return (rs > 0);
}

void solve()
{
   int n;
   cin >> n;
   
   if(n > 100)
   {
       cout << 0;
       return;
   }
       
   f(i,n) f(j,5) cin >> go[i][j];
    
   set<int> good;
  
   f(i,n)
   {
       vector<vi> vecs;
       
       good.insert(i);
       
       f(j,n)
       {
           if(i != j)
           {
               vector<int> tmp(5,0);
               f(k,5) tmp[k] = go[j][k] - go[i][k];
               vecs.pb(tmp);
           }
       }
       
       int sz = vecs.size();
       
       f(j,sz) for(int k=0;k<j;k++)
       {
           if(check(vecs[j],vecs[k]))
           {
               good.erase(i);
               break;
           }
       }
   }
   
   cout << good.size() << '\n';
   
   for(auto x : good) cout << x + 1 << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}