#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 1e9+7;
const int N = 2e6+10;
ll sil[N], odwr[N];
ll choose (int n, int k)
{
	if (k>n || k<0 || n<0) return 0;
	return sil[n] * odwr[k] % mod * odwr[n-k] % mod;
}

ll power (ll a, int k)
{
	ll pot = a;
	ll ret = 1LL;
	while (k>0)
	{
		if (k%2==1) ret = ret * pot %mod;
		pot = pot * pot % mod;
		k/=2;
	}
	return ret;
}
int m;

//Policz ile jest lasow o n wierzcholkach
int main ()
{
	sil[0] = 1LL;
	rep(i,1,N) sil[i] = sil[i-1] * ll(i) % mod;
	rep(i,0,N)
	{
		odwr[i] = power(sil[i], (int)mod - 2);
	}
	
	int n, a, b;
	scanf ("%d %d %d %d", &n, &m, &a, &b);
	
	ll res = 0LL;
	res+= sil[n-2] *  choose (m-1, n-2) % mod; //sama sciezka
	debug ("sama sciezka %lld \n", res);
	rep(l,2,n) //length of the path
	{
		ll path = choose (n-2, l-2)  * sil[l-2] % mod * choose (m -1, l-2) % mod;
		ll forest =  ll(l) * power (n, n - l -1) % mod * power(m, n-l) % mod;
		res = ((path * forest) % mod) + res % mod;
		res%=mod;
		
		debug ("of length %d: %lld * %lld\n", l, path, forest);
		
	}
	printf ("%lld\n", res);
}