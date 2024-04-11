#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std; 
typedef long long ll;
typedef long double ld;

const int N = 2e5+100;
const int K = 17993;
bitset <N> P;
vector <int> D[K];
map <int, int> Mapa;
int main ()
{
	//ios_base::sync_with_stdio(false);
	
	P.set();
	vector <ll> primes;
	rep(i,2,N) if (P[i])
	{
		Mapa[i] = primes.size();
		primes.pb(i);
		for (int x = i; x<N; x+=i) P[x] = 0;
	}
	
	vector <ll> rest;
	int n;
	scanf ("%d", &n);
	rep(q,0,n)
	{
		ll a;
		scanf ("%lld", &a);
		
		rep(i,0,K)
		{
			if (primes[i]*primes[i] > a) break;
			if (a%primes[i]==0)
			{
				int ile = 0;
				while (a%primes[i]==0) 
				{
					ile++;
					a/=primes[i];
				}
				D[i].pb(ile);
			}
		}
		
		if (a>1) D[Mapa[a]].pb(1);
	}
	
	ll res = 1LL;
	/*
	rep(i,0,K) if ((int)D[i].size() >0)
	{
		debug ("%lld: ", primes[i]);
		for (int x: D[i]) debug ("%d ", x);
		debug ("\n");
	}*/
	
	rep(i,0,K) if ((int)D[i].size() >= n-1)
	{
		if ((int)D[i].size()==n-1) D[i].pb(0);
		
		sort(D[i].begin(), D[i].end());
		int ile = max(D[i][0], D[i][1]);
		ll p = primes[i];
		rep(la,0,ile) res *=p;
	}
	printf ("%lld\n", res);
}