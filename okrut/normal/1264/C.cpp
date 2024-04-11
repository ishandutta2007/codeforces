#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = 1<<18;
const ll mod = 998244353;
ll ilo[T+T], sum[T+T], czas[T];
ll turn[101];

ll pot (ll a, int k)
{
	ll ret = 1;
	while (k>0)
	{
		if (k%2==1) ret = ret * a  % mod;
		a = a*a % mod;
		k /=2;
	}
	return ret;
}

ll suma (int l, int r)
{
	l--;
	r--; //na zewnatrz jest od 1
	l+=T;
	r+=T;
	
	ll ip = 1LL, sl = 0LL, sr = 0LL;
	
	while (l<r)
	{
		if (r%2==0)
		{
			sr = (sr + sum[r] * ip) % mod;
			ip = ip * ilo[r] % mod;
		}
		
		if (l%2==1)
		{
			sl = (sl * ilo[l] + sum[l]) % mod;
		}
		
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (r==l)
	{
		sr = (sr + sum[r] * ip) % mod;
		ip = ip * ilo[r] % mod;
	}
	return (sl * ip + sr) % mod;
}
int main ()
{
	rep(i,1,101) turn[i] = 100 * pot(i,mod-2) % mod;
	
	int n, q;
	scanf ("%d %d", &n, &q);
	rep(i,0,n) scanf ("%lld", &ilo[T+i]);
	
	rep(i,T,T+n) 
	{
		ilo[i] = turn[ilo[i]];
		sum[i] = ilo[i];
	}
	
	for (int i = T-1; i>0; i--) 
	{
		ilo[i] = ilo[i*2+1] * ilo[i*2] % mod;
		sum[i] = (sum[i*2+1] + ilo[i*2+1] * sum[i*2]) % mod;
	}
	
	set <int> ctrl;
	ctrl.insert(1);
	ctrl.insert(n+1);
	
	czas[1] = suma(1,n);
	ll stan = czas[1];
	
	rep(te,0,q)
	{
		int c;
		scanf ("%d", &c);
		
		if (ctrl.count(c)==1)
		{
			auto it = ctrl.find(c);
			stan-=czas[c];
			
			it --;
			int l = *it;
			it++; it++;
			int r = *it;
			ctrl.erase(c);
			
			stan-=czas[l];
			czas[l] = suma(l, r-1);
			stan+=czas[l];
		}
		else
		{
			ctrl.insert(c);
			auto it = ctrl.find(c);
			
			it--;
			int l = *it;
			it++; it++;
			int r = *it;
			
			stan-= czas[l];
			
			czas[l] = suma(l, c-1);
			czas[c] = suma(c, r-1);
			stan+=czas[l];
			stan+=czas[c];
		}
		
		while (stan<0) stan+=mod;
		stan%=mod;
		printf ("%lld\n", stan);
	}
}