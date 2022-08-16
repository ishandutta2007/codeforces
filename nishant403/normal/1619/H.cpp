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

const int BLK = 50;
const int N = 1e5 + 10;
int nxt[N];
int prv[N];
int jump[N];

void solve()
{
   int n,q;
   cin >> n >> q;
   
   int x;
    
   for(int i=1;i<=n;i++)
   {
       cin >> x;
       nxt[i] = x;
       prv[x] = i;
   }
    
   for(int i=1;i<=n;i++)
   {
       jump[i] = i;
       
       for(int j=1;j<=BLK;j++)
       {
           jump[i] = nxt[jump[i]];
       }
   }
    
   while(q--)
   {
       int t;
       cin >> t;
       
       if(t == 1)
       {
          int x,y;
          cin >> x >> y;
           
          int n_x = nxt[x];
          int n_y = nxt[y];
           
          nxt[x] = n_y;
          nxt[y] = n_x;
           
          prv[n_y] = x;
          prv[n_x] = y;
         
          int cur = -1;
           
          //change jump values of last BLK values in cycle of x and y
          cur = x;
          for(int i=1;i<=BLK;i++) cur = prv[cur];
           
          //find jump value of last element and for other elements,its just +1
          int j_x = cur;
           
          for(int i=1;i<=BLK;i++) j_x = nxt[j_x];
           
          for(int i=1;i<=BLK+1;i++)
          {
              jump[cur] = j_x;
              j_x = nxt[j_x];
              cur = nxt[cur];
          }
           
          cur = y;
          for(int i=1;i<=BLK;i++) cur = prv[cur];
        
          //find jump value of last element and for other elements,its just +1
          int j_y = cur;
           
          for(int i=1;i<=BLK;i++) j_y = nxt[j_y];
           
          for(int i=1;i<=BLK+1;i++)
          {
              jump[cur] = j_y;
              j_y = nxt[j_y];
              cur = nxt[cur];
          } 
       }
       else
       {
           int i,k;
           cin >> i >> k;
           
           while(k >= BLK)
           {
               i = jump[i];
               k -= BLK;
           }
           
           while(k > 0)
           {
               i = nxt[i];
               k--;
           }
           
           cout << i << '\n';
       }
   }
}

signed main()
{
    fast;
    
    int t = 1;
    
  //  cin >> t;
    
    while(t--)
        
    solve();
}