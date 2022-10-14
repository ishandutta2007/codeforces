#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;

ll pot (ll a, int wyk)
{
	ll ret = 1LL;
	while (wyk>0)
	{
		if (wyk%2==1) ret = a* ret % mod;
		a = a*a % mod;
		wyk/=2;
	}
	return ret;
}

const int N = 2e5+5;
ll sil[N], odwr[N];
ll choose (int n, int k)
{
	if (n<0 || k<0 || n<k) return 0;
	return sil[n] * odwr[k] % mod * odwr[n-k] % mod;
}

int main ()
{
	sil[0] = 1LL;
	rep(i,1,N) sil[i]  = sil[i-1] * ll(i) % mod;
	odwr[N-1] = pot(sil[N-1], mod-2);
	for (int i=N-1; i>0; i--) odwr[i-1] = odwr[i] * ll(i) % mod;
	
	int n, k, d=0;
	scanf ("%d %d", &n,&k);
	int curr, fi, old;
	scanf ("%d", &fi);
	old = fi;
	curr = fi;
	rep(i,1,n)
	{
		scanf ("%d", &curr);
		if (curr!=old) d++;
		old = curr;
	}
	if (curr!=fi) d++;
	
	debug ("d = %d, n = %d, k = %d\n", d, n, k);
	
	ll rowno = 0LL;
	rep(i,0,1+d/2)
	{
		ll c = choose(d, i) * choose(d-i, i) % mod * pot(k-2,d-2*i) % mod;
		debug ("dla %d: %lld\n", i, c);
		rowno+=c;
	}
	rowno%=mod;
	
	
	ll res = (mod + pot(k, d) - rowno) % mod;
	
	debug ("rowno = %lld, wiec res = %lld\n", rowno, res);
	
	
	res = res * pot(2, mod-2) % mod;
	
	res = res * pot(k, n-d) % mod;
	printf ("%lld\n", res);
}