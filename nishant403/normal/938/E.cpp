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
#define all(x) x.begin(),x.end()

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

const int N = 2e6 + 10;

int fact[N];

void init()
{
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%MOD;
}

int a[N];

int fun(int n,int x)
{
    int res = fact[n];
    
    res = (res*mod_pow(n-x,MOD-2))%MOD;
    
    return res;
}

signed main()
{
    init();
    
    fast;
    
    int n;
    cin >> n;
    
    f(i,n) cin >> a[i];
    sort(a,a+n);
    
    int res = 0;
    int ptr = 0;
    
    f(i,n)
    {
        while(a[ptr] < a[i]) ptr++;
        
        if(a[i] != a[n-1]) res += a[i]*fun(n,ptr);
        res %= MOD;
    }
    
    cout << res;
}