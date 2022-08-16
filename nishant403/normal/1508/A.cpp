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

bool check(string x,string y)
{
    int one = 0;
    int zero = 0;
    
    for(auto z : x) 
        if(z == '1') one++;
        else zero++;
        
    int res_a = 0;
    int res_b = 0;
    
    for(auto z : y)
    {
        if(z == '1')
        {
            if(one > 0)
            {
                one--;
                res_a++;
            }
        }
        else
        {
            if(zero > 0)
            {
                zero--;
                res_b++;
            }
        }
    }
    
    int n = x.length();
    
    
    if((res_a*2)>= n)
    {
        string res = "";
        
        //insert character 0 so that y becomes subsequence of res
        int id = 0;
        
        for(int i=0;i<n;i++)
        {
            while(id < n && y[id] == '0')
            {
                res += '0';
                id++;
            }
            
            res += x[i];
            
            if(id < n && y[id] == x[i]) id++;
        }
        
        while(id < n) 
        {
            res += y[id];
            id++;
        }
        
        cout << res << '\n';
        
        return 1;
    }
    else if((res_b*2) >= n)
    {
        string res = "";
        int id = 0;
        
        //insert character 1 so that y becomes subsequence of res
        for(int i=0;i<n;i++)
        {
            while(id < n && y[id] == '1')
            {
                res += '1';
                id++;
            }
            
            res += x[i];
            if(id < n && y[id] == x[i]) id++;
        }
        
        while(id < n) 
        {
            res += y[id];
            id++;
        }
        
        cout << res << '\n';
        
        return 1;
    }
    
    return 0;
}

void solve()
{
   int n;
   cin >> n;
    
   string s[3];
    f(i,3) cin >> s[i];
    
   f(i,3) f(j,3)
       if(i != j)
   {
       if(check(s[i],s[j]))
       {
           return;
       }
   }
    
   assert(1 == 0); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}