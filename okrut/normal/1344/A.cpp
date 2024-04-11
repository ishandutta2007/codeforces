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
		scanf ("%d", &n);
		vector <int> A(n), indeg(n,0);
		for (int &a: A) scanf ("%d", &a);
		bool err = false;
		rep(i,0,n)
		{
			int g = (i + n + (A[i] % n)) % n;
			indeg[g]++;
			if (indeg[g] > 1) err = true;
		}
		if (err) printf ("NO\n");
		else printf ("YES\n");
	}
}