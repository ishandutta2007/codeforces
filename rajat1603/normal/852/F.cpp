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
typedef pair<int,int> pii;

const int maxn = 1e6 + 200;
//const int md = 1e9 + 7;

ll arr[maxn];
ll pref[maxn];

ll modexp(ll a, ll ex, ll md) {
	ll ans = 1;
	while (ex > 0) {
		if (ex%2 == 1) {
			ans = (ans * a)%md;
		}
		a = (a*a)%md; ex >>= 1;
	}
	return ans;
}

int main() {
	ll n,m,a,q; sl(n); sl(m); sl(a); sl(q);
	ll cur = a; ll p = 1;
	while (cur != 1) {
		cur = (cur * a)%q;
		p++;
	}
	pref[0] = 1;

	for (int i = 1; i <= m; i++) {
		pref[i] = ((pref[i-1] * (m-i+1))%p) * modexp(i, p-2, p); pref[i] %= p;
		//cout<<pref[i]<<" ";
	}
	//cout<<endl;
	for (int i = 1; i <= m; i++) {
		pref[i] = (pref[i-1] + pref[i])%p;
	}

	for (int i = 1; i <= n; i++) {
		int z = min(m+1, n-i+1);
		//cout<<pref[z-1]<<endl;
		pl(modexp(a, pref[z-1], q)); psp;
	}
	endc;
}