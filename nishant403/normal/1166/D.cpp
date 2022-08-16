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

bool solve(int sum,int terms,int a,int b,int m)
{
    vector<int> vals(terms - 1,0);
    
    for(int i=terms-2;i>=0;i--)
    {
        int multiplier = 1;
        
        if(i >= 1) multiplier = (1LL<<(i-1));
        
        int div = sum / multiplier;
        
        vals[i] = min(div,m-1);
        
        sum -= multiplier*vals[i];
    }
    
    if(sum > 0) return 0;
    
    reverse(all(vals));
    
    for(auto & x : vals) x++;
    
    cout << terms << ' ';
    
    cout << a << ' ';
    
    int prev_sum = a;
    sum = a;
    
    for(auto x : vals)
    {
        sum = prev_sum + x;
        cout << sum << ' ';
        prev_sum += sum;
    }
    
    cout << '\n';
    
    return 1;
}

void solve()
{
   int a,b,m;
    cin >> a >> b >> m;
    
   if(a == b)
   {
       cout << 1 << ' ' << a << '\n';
       return;
   }
    
   int dif = b - a;
    
   if(dif >= 1 && dif <= m)
   {
       cout << 2 << ' ' << a << ' ' << b << '\n';
       return;
   }
    
   int sum_a = (a + 1);
    
   for(int i=3;i<=50;i++)
   {
       sum_a += sum_a;
       
       if(sum_a > b) break;
       
       int fixed_term = b - sum_a;
       
       if(solve(fixed_term,i,a,b,m)) return;
   }
    
   cout << -1 << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}