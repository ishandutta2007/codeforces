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
typedef double ld;
int n;
int s;
vector <int> sto;
int main ()
{
	scanf ("%d %d", &n, &s);
	if (n==2) 
	{
		printf ("%d\n", s);
		return 0;
	}
	sto.resize(n+1, 0);
	int a, b;
	rep(i,1,n)
	{
		scanf ("%d %d", &a, &b);
		sto[a]++;
		sto[b]++;
	}
	int l=0;
	rep(i,1,n+1) if (sto[i]==1) l++;
	debug ("jest %d lisci\n", l);
	printf ("%.9lf\n", ((ld)(s*2))/(ld)(l));
}