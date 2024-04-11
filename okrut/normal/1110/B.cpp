#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

vector <ll> len;

int main ()
{
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	ll first, last, a, b;
	scanf ("%lld", &b);
	first = b;
	rep(i,1,n)
	{
		scanf ("%lld", &a);
		len.pb(a - b -1);
		b = a;
	}
	last = b;
	sort(len.begin(), len.end());
	ll save = 0;
	rep(i,0,k-1)
	{
		save+=len.back();
		len.pop_back();
	}
	printf ("%lld\n", last - first +1 - save);
}