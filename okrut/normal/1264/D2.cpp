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
const int N = 1e6+5;
ll sil[N], odwr[N], pref[N][2];
ll choose (int n, int k)
{
	if (n<0  || k<0 || n<k) return 0;
	return sil[n] * odwr[k] % mod * odwr[n-k] % mod;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	sil[0] = 1;
	rep(i,1,N) sil[i] = sil[i-1] * ll(i) % mod;
	odwr[N-1] = 1LL;
	ll a= sil[N-1];
	int k = mod-2;
	while (k>0)
	{
		if (k%2==1) odwr[N-1] = odwr[N-1] * a % mod;
		a = a*a % mod;
		k/=2;
	}
	for (int i = N-1; i>0; i--) odwr[i-1] = odwr[i] * ll(i) % mod;
	
	string s;
	cin>>s;
	
	int pyt = 0, za = 0;
	for (char c: s) 
	{
		if (c=='?') pyt++;
		if (c==')') za++;
	}
	
	rep(i,0,(int)s.size()+1)
	{
		if (i>0)
		{
			pref[i][0] = pref[i-1][0];
			pref[i][1] = pref[i-1][1];
		}
		pref[i][1] += choose(pyt, i);
		pref[i][0] += choose(pyt-1, i);
		
		debug ("dla %d: %lld %lld\n", i, pref[i][0], pref[i][1]);
		
		pref[i][1] %=mod;
		pref[i][0] %=mod;
	}
	
	ll res = 0LL;
	
	int p0 = 0;
	int p1 = za;
	int l1 = pyt;
	int licz = p1-p0+l1;
	for (char c: s)
	{
		if (c==')') licz--;
		if (c=='(')
		{
			if (licz>0) res += pref[licz-1][1];
			licz--;
		}
		if (c=='?')
		{
			licz--;
			if (licz>0) res += pref[licz-1][0];
		}
		
	}
	
	res%=mod;
	cout<<res <<"\n";
}