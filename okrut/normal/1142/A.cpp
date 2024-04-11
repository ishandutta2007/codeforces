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
int a, b;
ll n, k;
int main ()
{
	scanf ("%lld %lld %d %d", &n, &k, &a, &b);
	
	ll minl = 1e12, maksl = -1; 
	
	int start;
	start = b-a;
	if (start<=0) start+=k;
	ll opcja;
	for (ll l = start; l<= n * k; l+=k) 
	{
		opcja  = n*k/ __gcd(n*k, l);
		minl= min(minl, opcja);
		maksl = max(maksl, opcja);
	}
	
	start = b + a;
	for (ll l = start; l<= n * k; l+=k) 
	{
		opcja  = n*k/ __gcd(n*k, l);
		minl= min(minl, opcja);
		maksl = max(maksl, opcja);
	}
	
	start = k - b + a;
	for (ll l = start; l<= n * k; l+=k) 
	{
		opcja  = n*k/ __gcd(n*k, l);
		minl= min(minl, opcja);
		maksl = max(maksl, opcja);
	}
	
	start = k - b + k - a;
	for (ll l = start; l<= n * k; l+=k) 
	{
		opcja  = n*k/ __gcd(n*k, l);
		minl= min(minl, opcja);
		maksl = max(maksl, opcja);
	}
	
	printf ("%lld %lld\n", minl, maksl);
}