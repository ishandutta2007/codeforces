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

const int N = 3e5+100;
int tab[N];
int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		rep(i,1,n+1) scanf ("%d", &tab[i]);
		bool found  = false;
		rep(i,2,n+1) if (!found && abs(tab[i-1] - tab[i]) > 1)
		{
			printf ("YES\n%d %d\n", i-1, i);
			found = true;
		}
		if (!found) printf ("NO\n");
	}
}