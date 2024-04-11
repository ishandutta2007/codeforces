#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ld eps = 1e-10;

bool solve (int n, int R, int r)
{
	if (R<r) return false;
	
	if (n==1) return (R>=r);
	
	if (n==2) return (R>=r*2);
	
	int rp = R - r;
	
	ld alpha = acos(-1.0) * 2.0 / ld(n);
	
	ld betha = acos( ld(2*rp*rp - 4*r*r)/ld(2*rp*rp));
	
	return alpha + eps > betha;
	
}	

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, R, r;
	scanf ("%d %d %d", &n, &R, &r);
	
	if (solve(n, R, r)) printf ("YES\n");
	else printf ("NO\n");
}