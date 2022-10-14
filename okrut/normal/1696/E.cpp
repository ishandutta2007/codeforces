#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 1e9+7;

const int N = 5e5;
ll Fac[N], Inw[N];

ll choose (int n, int k)
{
	return Fac[n] * Inw[k] % mod * Inw[n - k] % mod;
}

int main()
{
	Fac[0] = 1;
	rep(i,1,N) Fac[i] = Fac[i-1] * ll(i) % mod;
	Inw[N-1] = 1;
	{
		int x = mod - 2;
		ll y = Fac[N-1];
		while (x > 0) {
			if (x & 1) Inw[N-1] = Inw[N-1] * y % mod;
			y = y*y % mod;
			x >>= 1;
		}
	}
	for (int i = N-1; i > 0; i--) Inw[i-1] = Inw[i] * ll(i) % mod;
	
	
	ll res = 0;
	int n;
	scanf ("%d", &n);
	n++;
	
	vector <int> A(n);
	for (int &a: A) scanf ("%d", &a);
	
	while (!A.empty() and A.back() == 0) {
		A.pop_back();
		n--;
	}
	
	if (A.empty()) {
		printf ("0\n");
		return 0;
	}
	
	A.pb(0);
	debug ("My array (%d): ", n);
	//for (int a: A) debug ("%d ", a);
	debug ("\n");
	
	vector <pair<int, ll> > event;
	rep(i,0,n) {
		rep(j,A[i+1],A[i]) event.pb({j + i + 1, choose(i+j,i)} );
		event.pb({i+A[i], choose(i+A[i]-1, i)});
	}
	
	sort(event.begin(), event.end());
	auto e = event.begin();
	ll clicks = 1;
	rep(i,0,N) {
		debug ("Layer %d: \n", i);
		
		while (e != event.end() and e->fi == i) {
			debug ("Loose %lld clicks on (%d)\n", e->se, e->fi);
			clicks = (clicks + mod - e->se) % mod;
			e++;
		}
		
		if (clicks == 0) {
			break;
		}
		
		res += clicks;
		
		debug ("Layer %d: %lld clicks\n", i, clicks);
		
		clicks *= 2;
		clicks %= mod;
	}
	
	printf ("%lld\n", res % mod);
}