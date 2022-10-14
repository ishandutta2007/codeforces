#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=998244353;
ll n, m, k;
ll pow (ll a)
{
	ll b=mod-2LL; //oto moj wykladnik
	ll pot=a;
	ll ret=1;
	while (b>0)
	{
		if (b%2==1) ret*=pot;
		pot*=pot;
		if (pot>=mod) pot%=mod;
		if (ret>=mod) ret%=mod;
		b=b/2LL;
	}
	return ret;
}
int main ()
{
	scanf ("%lld %lld %lld", &n, &m, &k);
	//silnia
	ll sil=1;
	for (ll a=n-k; a<n; a++) 
	{
		sil*=a;
		if (sil>=mod) sil%=mod;
	}
	for (ll a=1; a<=k; a++)
	{
		sil*=pow(a);
		if (sil>=mod) sil%=mod;
	}
	ll kol=m;
	rep(i,0,k) 
	{
		kol*=m-1LL;
		if (kol>=mod) kol%=mod;
	}
	printf ("%lld\n", (kol*sil)%mod);
}