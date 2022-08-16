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
 
const int MOD = 1e9+7;
const int N = 2e5+10;
int fact[N];
int ifact[N];
 
int mod_add(int a,int b)
{
    int sum = a+b;
    return (sum >= MOD) ? sum - MOD : sum;
}
 
int mod_sub(int a,int b)
{
    int diff = a-b;
    return diff < 0 ? diff+MOD : diff;
}
 
int mod_mul(int a,int b)
{
    return ((long long)a*b)%MOD;
}
 
int mod_pow(int a,int b)
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
 
void pre()
{
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = mod_mul(fact[i-1],i);
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--) ifact[i] = mod_mul(ifact[i+1],i+1);
    
}
 
int ncr(int n,int r)
{ 
    if(r>n) return 0;
    return mod_mul(fact[n],mod_mul(ifact[r],ifact[n-r]));
}
 
int store[2003];
 
int way(pii a,pii b)
{
 if(a.F > b.F || a.S > b.S) return 0;
 return ncr(b.F+b.S-(a.F+a.S),b.S-a.S);
}
 
signed main()
{
    fast;
    pre();
 
    int n,nn,m;
    cin >> n >> nn >>  m;
 
    pii start = {1,1}, end ={n,nn};
 
    pii go[m];
    f(i,m) cin >> go[i].F >> go[i].S;
 
    sort(go,go+m);
 
    int res = way(start,end);
 
    f(i,m)
    {
          store[i] = way(start,go[i]);
     
          f(j,i) 
              store[i] = mod_sub(store[i],mod_mul(store[j],way(go[j],go[i])));
 
           res = mod_sub(res,mod_mul(store[i],way(go[i],end)));
    }
 
    cout << res;
}