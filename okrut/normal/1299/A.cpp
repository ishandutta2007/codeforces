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

const int N = 1e5+10;
unsigned int tab[N], Pref[N], Suf[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	rep(i,1,n+1)
	{
		int a;
		scanf ("%d", &a);
		tab[i] = a;
	}
	Pref[0] = (~0);
	
	rep(i,1,n+1)
	{
		Pref[i] = Pref[i-1] & (~tab[i]);
	}
	
	Suf[n+1] = (~0);
	for (int i=n; i>0; i--)
	{
		Suf[i] = Suf[i+1] & (~tab[i]);
	}
	
	pair <int, unsigned int> best = {1,0};
	
	rep(i,1,n+1)
	{
		unsigned int curr = (Pref[i-1] & Suf[i+1]) & tab[i];
		if (best.se < curr)
		{
			best.se = curr;
			best.fi = i;
		}
	}
	
	
	printf ("%d ", tab[best.fi]);
	rep(i,1,n+1) if (i!=best.fi) printf ("%d ", tab[i]);
	printf ("\n");
}