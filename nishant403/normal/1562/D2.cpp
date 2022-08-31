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

const int N = 3e5 + 100;
int n,q;
int pluss[N];
int minuss[N];

int eval(int l,int r)
{
   int res = pluss[l] - pluss[l+1];
           
   res -= minuss[l] - minuss[l+1];

   r++;

   if(r < n)
   {
       int res2 = pluss[r];
       if(r+1 < n) res2 -= pluss[r+1];

       res2 -= minuss[r];
       if(r+1 < n) res2 += minuss[r+1];

       if((r-l) & 1) res += res2;
           else res -= res2;
   }
    
    return res;
}

int go(int l,int r)
{
    if(l == r) return l;
    
    int vv = eval(l,r);
    
    if(vv > 0) vv = (vv + 1)/2;
    else vv = (vv - 1)/2;
    
    int L = l;
    int R = r;
    int res = r + 1;
    
    while(L <= R)
    {
        int mid = (L + R)/2;
        int val = eval(l,mid);
        
        if(vv < 0)
        {
            if(val > vv)
            {
                L = mid + 1;
            }
            else
            {
                res = mid;
                R = mid - 1;
            }
        }
        else
        {
            
            if(val < vv)
            {
               L = mid + 1;
            }
            else
            {
                res = mid;
                R = mid - 1;
            }
        }
    }
    
    return res;
}

void solve()
{
   cin >> n >> q;
    
   string s;
   cin >> s;
    
   f(i,n+2) pluss[i] = minuss[i] = 0; 
    
    f(i,n) if(s[i] == '+') pluss[i]++;
        else minuss[i]++;
        
    for(int i=n-3;i>=0;i--)
    {
        pluss[i] +=  pluss[i+2];
        minuss[i] += minuss[i+2];
    }
        
   while(q--)
   {
       int l,r;
       cin >> l >> r;
       l--,r--;
       
       if(l == r) 
       {
           cout << 1 << '\n';
           cout << l + 1 << '\n';
       }
       else
       {
           int res = eval(l,r);
           
           if(res == 0) cout << 0 << '\n';
           else if(res & 1)
           {
               cout << 1 << '\n';
               cout << go(l,r) + 1 << '\n';
           }
           else
           {
               cout << 2 << '\n';
               cout << go(l,r-1) + 1 << ' ' << r + 1 << '\n';
           }
       }
       
   }
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}