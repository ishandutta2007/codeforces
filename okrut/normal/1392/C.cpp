#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		vector <int> tab(n);
		for (int &x: tab) scanf ("%d", &x);
		ll res = 0;
		for (int i = n-1; i>0; i--)
		{
			res += ll( max(0, tab[i-1] - tab[i]));
		}
		printf ("%lld\n", res);
	}
}