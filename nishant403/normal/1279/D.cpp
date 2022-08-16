#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int MOD = 998244353;
const int N = 1e6+10;

int mod_add(int a,int b)
{
    int sum = a+b;
    return (sum >= MOD) ? sum-MOD : sum;
}

int mod_sub(int a,int b)
{
    int diff = a-b;
    return (diff < 0) ? diff+MOD : diff;
}

int mod_mul(int a,int b)
{
    return ((long long)a*b)%MOD;
}

int mod_pow(int a, int b, int M = MOD)
{
	int res = 1;
    
	while(b)
	{
		if(b&1) res=mod_mul(res,a);
		a=mod_mul(a,a);
        b>>=1;
	}
    
	return res;
}

int mp[N];
vi g[N];

void solve()
{
   int n,x,sz;
   cin >> n;
    
   f(i,n)
   {
       cin >> sz;
    
       f(j,sz)
       {
           cin >> x;
           g[i].pb(x);
           mp[x]++;
       }
   }
    
   int res = 0;  
   
   f(i,n)
   {
       int temp = 0;
       
       for(auto x : g[i]) temp = mod_add(temp,mp[x]);
       
       temp = mod_mul(temp,mod_pow(g[i].size(),MOD-2));
       temp = mod_mul(temp,mod_pow(n,MOD-2));
       
       res = mod_add(temp,res);
   }
    
   res=mod_mul(res,mod_pow(n,MOD-2));
    
   cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}