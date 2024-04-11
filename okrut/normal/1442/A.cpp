#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

bool solve (vector <int> &A)
{
	int can = 1e7, must = 0;
	
	for (int &a: A)
	{
		a-=must;
		if (a<0) return false;
		
		if (a<=can)
		{
			can = min(a, can);
			a = 0;
		} else {
			a-=can;
			must += a;
		}
	}
	
	return true;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n;
		scanf ("%d", &n);
		vector <int> A(n);
		for (int &a: A) scanf ("%d", &a);
		
		if (solve(A)) printf ("YES\n");
		else printf ("NO\n");

	}
}