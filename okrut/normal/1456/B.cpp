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
	int n;
	scanf ("%d", &n);
	
	if (n > 60) {
		printf ("1\n");
		return 0;
	}
	
	vector <int> tab(n);
	for (int &a: tab) scanf ("%d", &a);
	
	int best = n;
	
	rep(l,0,n) rep(r,l+1,n) rep(m,l,r) {
		
		int left = 0;
		rep(i,l,m+1) left^=tab[i];
		int right = 0;
		rep(i,m+1,r+1) right^=tab[i];
		
		if (left > right) {
			best = min(best, r - l -1);
		}
	}
	
	printf ("%d\n", (best < n ? best : -1));
}