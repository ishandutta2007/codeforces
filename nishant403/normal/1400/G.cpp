#include <bits/stdc++.h>
using namespace std;
   
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int> 

const int MOD = 998244353;
const int N = 3e5 + 10;
const int M = 21;

int store[N][M+M];

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

	while(b > 0)
	{
		if(b&1) res=mod_mul(res,a);
		a=mod_mul(a,a);
        b>>=1;
	}

	return res;
}

vector<int> fact(N),ifact(N);

void precalc()
{
    //Factorial and Inverse Factorial
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = mod_mul(fact[i-1],i);
        
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    for(int i=N-2;i>=0;i--) ifact[i] = mod_mul(ifact[i+1],i+1);
}

int ncr(int n,int k)
{
    if(k > n) return 0;
    if(k < 0) return 0;
    return mod_mul(fact[n],mod_mul(ifact[n-k],ifact[k]));
}

pii range[N];
pii rest[M];
int tot[N];
int n,m;

void solve()
{
    cin >> n >> m;
    
   f(i,n) cin >> range[i].F >> range[i].S;
   f(i,m) cin >> rest[i].F >> rest[i].S; 
   f(i,m) rest[i].F--,rest[i].S--;
    
   f(i,n) tot[range[i].F]++;
   f(i,n) tot[range[i].S+1]--;
   f(i,N-1) tot[i+1]+=tot[i];
    
   for(int i=1;i<=n;i++) 
    for(int j=0;j<=m+m;j++)
       store[i][j] = mod_add(ncr(tot[i] - j,i - j),store[i-1][j]);
   
   int res = 0;
    
   for(int i=0;i<(1LL<<m);i++) 
   {
       int l = 0;
       int r = n;
       unordered_set<int> st;
       
       for(int j=0;j<m;j++) if(i&(1<<j)) st.insert(rest[j].F),st.insert(rest[j].S);
       
       for(auto x : st) l = max(l,range[x].F), r = min(r,range[x].S);
       
       if(l > r) continue;
       
       int sz = (int)st.size();
       
       int temp = store[r][sz];
       if(l > 0) temp = mod_sub(temp,store[l-1][sz]);
       
       if(__builtin_popcount(i) % 2 == 1) res = mod_sub(res,temp);
       else res = mod_add(res,temp);
   }
 
   cout << res;
}

signed main()
{
    fast;
    
    precalc();
            
    solve();
}