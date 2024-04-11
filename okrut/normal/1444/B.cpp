#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;
const int N = 1e6;
ll F[N], Inw[N];

ll inw (ll a)
{
	int k = mod-2;
	ll res = 1;
	rep(i,0,30) 
	{
		if (k& (1<<i)) res = res*a % mod;
		a = a*a % mod;
	}
	return res;
}

ll choose (int n, int k)
{
	if (n<0 or k<0 or k>n) return 0;
	return F[n] * Inw[k] % mod * Inw[n-k] % mod;
}

int main ()
{
	F[0] = 1;
	rep(i,1,N) F[i] = F[i-1] * ll(i) % mod;	
	Inw[N-1] = inw(F[N-1]);
	for (int i=N-1; i>0; i--) Inw[i-1] = Inw[i] * ll(i) % mod;
	
	
	int n;
	scanf ("%d", &n);
	vector <ll> tab(n*2);
	for (ll &a: tab) scanf ("%lld", &a);
	sort(tab.begin(), tab.end());
	
	ll ile = choose(n*2, n);
	ll res = 0;
	
	rep(i,0,n) res -= tab[i];
	rep(i,n,n+n) res += tab[i];
	
	res%=mod;
	res = res * ile % mod;
	printf ("%lld\n", res);
	
}