#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

ll Bucks[4];
const int N = 6e3;
pair <int, int> Pkt[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	
	rep(i,0,n) {
		scanf ("%d %d", &Pkt[i].fi, &Pkt[i].se);
		Pkt[i].fi/=2;
		Pkt[i].se/=2;
	}
	
	ll res = 0;
	
	rep(i,0,n) {
		
		rep(j,0,4) Bucks[j] = 0;
		
		rep(j,0,n) if (j != i) {
			int x = abs(Pkt[j].fi - Pkt[i].fi);
			int y = abs(Pkt[j].se - Pkt[i].se);
			
			Bucks[(x & 1)*2 + (y & 1)]++;
		}
		
		debug ("\nFor (%d %d)\n", Pkt[i].fi, Pkt[i].se);
		
		rep(a,0,4) rep(b,a+1,4) {
		
			int g = 1;
			if (a) g++;
			if (b) g++;
			
			debug ("Bucks (%lld * %lld) --> %d\n", Bucks[a], Bucks[b], g);
			
			if (g % 2 == 0) res += Bucks[a] * Bucks[b];
		}
		
		rep(a,0,4) {
			res += Bucks[a] * (Bucks[a] - 1) / 2;
		}
	}
	
	printf ("%lld\n", res/3);
}