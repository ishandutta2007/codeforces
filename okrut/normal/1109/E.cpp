#pragma GCC optimize "O3"
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

const int T = 1<<17;
int n;
ll mod;
int wyk[T+T][10], lazytab[T+T][10], curr[10], tab[T];
ll sum[T+T], lazy[T+T]; //suma - reszta
vector <int> dziel;
ll prep[10][T*20+3];

int d;
int phi;
ll pot (ll a, int k)
{
	ll ret = 1;
	while (k>0)
	{
		if (k%2) ret = ret * a % mod;
		a = a*a % mod;
		k/=2;
	}
	return ret;
}
void up (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		rep(i,0,d) 
		{
			lazytab[a*2][i]+=lazytab[a][i];
			lazytab[a*2+1][i]+=lazytab[a][i];
		}
		lazy[a*2] = lazy[a*2] * lazy[a] % mod;
		lazy[a*2+1] = lazy[a*2+1] * lazy[a] % mod;
	}
	rep(i,0,d) 
	{
		wyk[a][i]+=lazytab[a][i];
		lazytab[a][i] = 0;
	}
	sum[a] = sum[a] * lazy[a] % mod;
	lazy[a] = 1;
}
void update (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		rep(i,0,d) 
		{
			lazytab[a*2][i]+=lazytab[a][i];
			lazytab[a*2+1][i]+=lazytab[a][i];
		}
		lazy[a*2] = lazy[a*2] * lazy[a] % mod;
		lazy[a*2+1] = lazy[a*2+1] * lazy[a] % mod;
		
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		
		ll lsum = sum[a*2], rsum = sum[a*2+1];
		lazy[a] = 1;
		rep(i,0,d) 
		{
			lazytab[a][i] = 0;
			wyk[a][i] = min(wyk[a*2][i], wyk[a*2+1][i]);
			lsum= lsum * prep[i][wyk[a*2][i] - wyk[a][i]] % mod;
			rsum= rsum * prep[i][wyk[a*2+1][i] - wyk[a][i]] % mod;
		}
		sum[a] = lsum + rsum % mod;
	}
	else up(a, lewy, prawy);
}
void mnoz (int left, int right, ll x, int a = 1, int lewy = 1, int prawy = n)
{
	up(a, lewy, prawy);
	if (left<=lewy && right>=prawy)
	{
		rep(i,0,d) lazytab[a][i]=curr[i];
		lazy[a]  = x;
	}
	else
	{
		if (left<=mitte) mnoz (left, right, x, a*2, lewy, mitte);
		if (right>mitte) mnoz (left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}
ll read (int left, int right, int a =1 , int lewy = 1, int prawy = n)
{
	up(a, lewy, prawy);
	if (left<=lewy && right>=prawy)
	{
		ll ret = sum[a];
		rep(i,0,d) 
		{
			ret = ret * prep[i][wyk[a][i]] % mod;
		}
		return ret;
	}
	else
	{
		ll ret = 0;
		if (left<=mitte) ret+=read (left, right, a*2, lewy, mitte);
		if (right>mitte) ret+=read (left, right, a*2+1, mitte+1, prawy);
		while (ret>=mod) ret-=mod;
		return ret;
	}
}
void init (int a=1, int lewy = 1, int prawy = n)
{
	lazy[a] = 1;
	if (lewy<prawy)
	{
		init (a*2, lewy,mitte);
		init(a*2+1, mitte+1, prawy);
		update(a, lewy, prawy);
	}
	else
	{
		rep(i,0,d)
		{
			while (tab[lewy]%dziel[i]==0)
			{
				tab[lewy]/=dziel[i];
				wyk[a][i]++;
			}
		}
		sum[a] = tab[lewy];
	}
}
int main ()
{
	scanf ("%d %lld", &n, &mod);
	
	rep(i,1,n+1) scanf ("%d", &tab[i]);
	ll p = 2, m = mod;
	phi  = 1;
	while (p*p <= m)
	{
		if (m % p==0)
		{
			d++;
			dziel.pb(p);
			int x = 0;
			while (m%p==0) 
			{
				m/=p;
				x++;
			}
			phi*= pot(p, x) - pot(p, x-1);
		}
		p++;
	}
	if (m>1) 
	{
		d++;
		dziel.pb(m);
		phi*= pot(m, 1)  - pot(m, 0);
	}
	while (phi<0) phi+=mod;
	rep(i,0,d)
	{
		prep[i][0] = 1;
		rep(j,1,T*20+1) 
		{
			prep[i][j] = prep[i][j-1] * ll(dziel[i]) % mod;
		}
	}
	
	init();
	
	int q;
	scanf ("%d", &q);
	rep(i,0,q)
	{
		int type, l, r, x;
		scanf ("%d", &type);
		if (type==1)
		{
			scanf ("%d %d %d", &l, &r, &x);
			rep(i,0,d)
			{
				curr[i] = 0;
				while (x%dziel[i]==0) 
				{
					x/=dziel[i];
					curr[i]++;
				}
			}
			mnoz(l, r, x);
		}
		if (type==2)
		{
			scanf ("%d %d", &r, &x);
			rep(i,0,d)
			{
				curr[i] = 0;
				while (x%dziel[i]==0)
				{
					x/=dziel[i];
					curr[i]--;
				}
			}
			mnoz(r, r, pot(x, phi-1));
		}
		if (type==3)
		{
			scanf ("%d %d", &l, &r);
			printf ("%lld\n", read(l,r));
		}
	}
}