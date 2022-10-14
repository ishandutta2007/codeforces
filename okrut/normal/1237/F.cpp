#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug // 
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;
const int N = 3601;
ll pot[N];
int T[2][N], wol[2]; //taken or not
ll dp[2][N][N]; //[place][no_of_pairs]
ll sil[N], odwr[N];
ll choose (int n, int k)
{
	if (k<0 || n<0 || k>n) return 0;
	return sil[n] * odwr[k] % mod * odwr[n-k] % mod;
}
int main ()
{
	sil[0] = 1LL;
	rep(i,1,N) sil[i] = sil[i-1] * ll(i) % mod;
	odwr[N-1] = 1LL;
	ll p = sil[N-1];
	int wyk = mod-2LL;
	while (wyk>0)
	{
		if (wyk%2) odwr[N-1] = odwr[N-1] * p % mod;
		p = p*p % mod;
		wyk/=2;
	}
	for (int i = N-1; i>0; i--) odwr[i-1] = odwr[i] * ll(i) % mod;
	
	
	int h, w, n;
	scanf ("%d %d %d", &h, &w, &n);
	int a, b;
	rep(i,0,n*2)
	{
		scanf ("%d %d", &a, &b);
		T[0][a]++;
		T[1][b]++;
	}
	int dim[2] = {h+1, w+1};
	rep(i,0,2) rep(j,1,dim[i]) if (T[i][j]==0) wol[i]++;
	
	rep(k,0,2)
	{
		dp[k][0][0] = 1LL; 
		rep(pos,1,dim[k]) rep(i,0,dim[k]) //ile
		{
			if (i>0 && pos>1 && T[k][pos-1]==0 && T[k][pos]==0) dp[k][pos][i]+=dp[k][pos-2][i-1];
			dp[k][pos][i]+=dp[k][pos-1][i];
			dp[k][pos][i]%=mod;
		}
	}
	
	ll res = 0LL;
	rep(pion,0,w+1) rep(poz,0,h+1)
	{
		ll d1 = dp[0][h][pion] * choose (wol[0] - pion*2, poz) % mod;
		ll d2 = dp[1][w][poz] * choose(wol[1] - poz*2, pion) % mod;
		ll d3 = sil[pion] * sil[poz] % mod;
		ll d = (d1 * d2 % mod) * d3 % mod;
		res = (res + d) % mod;
	}
	printf ("%lld\n", res);
}