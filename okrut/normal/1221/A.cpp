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

const int N = 2048;

int main ()
{
	int q, n, a;
	scanf ("%d", &q);
	rep(r,0,q)
	{
		scanf ("%d", &n);
		vector <int> tab(N+1, 0);
		rep(i,0,n)
		{
			scanf ("%d", &a);
			if (a<=N) tab[a]++;
		}
		for (int x = 1; x<N; x*=2)
		{
			tab[x*2] += tab[x]/2;
		}
		if (tab[N]>=1) printf ("YES\n");
		else printf ("NO\n");
	}
}