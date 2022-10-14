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
	ll a, b, c;
	scanf ("%lld %lld %lld", &a, &b, &c);
	ll res = 2LL * (c + min(a, b));
	if (a!=b) res++;
	printf ("%lld\n", res);
}