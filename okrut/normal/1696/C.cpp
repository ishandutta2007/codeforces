#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

vector <pair <ll, ll> > normal(ll m, vector <ll> &arr)
{
	vector <pair <ll, ll> > norm;
	for (ll x: arr) {
		ll cnt = 1;
		while (x % m == 0) {
			x /= m;
			cnt *= m;
		}
		
		if (!norm.empty() and norm.back().fi == x) {
			norm[(int)norm.size()-1].se += cnt;
		} else {
			norm.pb({x, cnt});
		}
	}
	return norm;
} 

int main()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, m;
		scanf ("%d %d", &n, &m);
		vector <ll> A(n);
		for (ll &a: A) scanf ("%lld", &a);
		int k;
		scanf ("%d", &k);
		vector <ll> B(k);
		for (ll &b: B) scanf ("%lld", &b);
		
		if (normal(m, A) == normal(m, B)) printf ("Yes\n");
		else printf ("No\n");
	}
}