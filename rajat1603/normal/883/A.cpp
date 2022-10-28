#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%.12f",n)
#define psp printf(" ")
#define endc printf("\n")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

const int maxn = 2e5 + 7; 
const ll inf = 1e18 + 500;

ll t[maxn];
ll n,a,d;

pii g (ll l, ll r) {
	
	//cout<<"?? "<<l<<" : "<<r<<endl;

	ll p = l/a, q = r/a; if (p * a < l) p++;
	q = min(q, n);
	if (p > n) return mp(1, r);
	
	ll it =	(d/a) + 1;
	
	ll z = q - p + 1;

	if (z == 0) {
		return mp(1, r);
	}

	ll ans = z / it, lft = z % it, al = (q - lft + 1) * a;

	ll ls = (q - lft - it + 1);

	if (lft == 0) {
		if (a * ls <= r && r <= a * ls + d) {
			return mp(ans, a * ls);
		}
		return mp(ans + 1, r);
	}

	if (al + d < r) {
		return mp(ans + 2, r);
	}
	
	return mp(ans + 1, al);
}


int main() {
	int m; sl(n); sd(m); sl(a); sl(d);
	for (int i = 0; i < m; i++) sl(t[i]);

	m = unique(t, t + m) - t;

	pii z = g(1, t[0]);

	ll ans = z.first, last = z.second;

	//if (last < 0) { last = t[0]; ans++; }

	//cout<<ans<<" : "<<last<<endl;

	int i = 0;

	while (i < m) {
		if (t[i] <= last + d) { i++; continue; }

		pii z = g(last + d + 1, t[i]);

		ans += z.first; last = z.second;

		//if (last < 0) { last = t[i]; ans++; }

		//cout<<ans<<" : "<<last<<endl;
	}
	
	if (n * a >= last + d + 1) ans += g(last + d + 1, n * a).first;

	pl(ans); endc;
}