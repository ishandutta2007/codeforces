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


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		int k1, k2;
		scanf ("%d %d %d", &n, &k1, &k2);
		int m1 = 0, m2 = 0;
		rep(i,0,k1) 
		{
			int a;
			scanf ("%d", &a);
			m1 = max(m1, a);
		}
		rep(i,0,k2)
		{
			int a;
			scanf ("%d", &a);
			m2 = max(m2, a);
		}
		if (m1 > m2) printf ("YES\n");
		else printf ("NO\n");
	}
}