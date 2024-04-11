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

const int N = 2e5+100;

ll A[N], BON[N];
map <pair <int, int>, int> mapa;
int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,1,n+1) scanf ("%lld", &A[i]);
	ll sum = 0;
	rep(i,1,n+1) sum+=A[i];
	
	int q;
	scanf ("%d", &q);
	rep(i,0,q)
	{
		int s, t, u;
		scanf ("%d %d %d", &s, &t, &u);
		pair <int, int> p = mp(s,t);
		if (mapa.count(p)>0)
		{
			int w = mapa[p];
			if (BON[w] <= A[w]) sum++;
			BON[w] --;
			mapa.erase(p);
		}
		if (u>0)
		{
			if (BON[u] < A[u]) sum--;
			BON[u]++;
			mapa[p] = u;
		}
		
		printf ("%lld\n", sum);
	}
}