#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

int A, B, C;

void play (ll a, ll b, ll c)
{
	ll r = max( max(a,b), c);
	ll y = 3LL*r - a - b - c;
	printf ("%lld\n", y);
	fflush(stdout);
	
	int k;
	scanf ("%d", &k);
	
	if (k==1) a+=y;
	if (k==2) b+=y;
	if (k==3) c+=y;
	
	vector <ll> tab = {a,b,c};
	sort(tab.begin(), tab.end());
	
	if (tab[1] -  tab[0] == tab[2] - tab[1])
	{
		debug ("I win\n");
		printf ("%lld\n", tab[1] - tab[0]);
	}
	else play(a,b,c);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	ll a, b, c;
	scanf ("%lld %lld %lld", &a, &b, &c);
	
	printf ("First\n");
	
	play(a,b,c);
	
}