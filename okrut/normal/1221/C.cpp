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
	int q;
	scanf ("%d", &q);
	rep(i,0,q)
	{
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		printf ("%d\n", min(min(a,b), (a+b+c)/3));
	}
}