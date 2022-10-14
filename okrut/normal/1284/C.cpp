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

const int N = 250005;

ll sil[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n; ll mod;
	scanf ("%d %lld", &n, &mod);
	
	sil[0] = 1;
	rep(i,1,N) sil[i] = sil[i-1] * ll(i) % mod;
	
	ll res = 0LL;
	rep(len,1,n+1)
	{
		//ustalamy zbior elementow
		res += (n-len +1LL) * (n - len + 1LL) % mod * sil[len] % mod * sil[n-len] % mod;
		res %=mod;
	}
	printf ("%lld\n", res);
}