// NOIP RP++!!!!!!!!!!!!
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define NOIPRPADD 1
using namespace std;
const int N = 3e5;
int n, m;
ll All, a[N], sav[N];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 0, n - 1) scanf("%lld", &a[i]);
	while(m--) {
		int opt, x; ll k; scanf("%d%d%lld", &opt, &x, &k);
		if(opt == 1) {
			a[x] = k;
			continue;
		}
		All = 0;
		L(i, 0, n) All += a[i] * (1 << i);
		if(All < k) {
			puts("-1");
			continue;
		}
		ll res = 0, sum = 0;
		L(i, 0, x) k -= a[i], sum += ((1 << i) - 1) * a[i];
		if(k < 0) {
			puts("0");
			continue;
		} 
		L(i, 0, n) sav[i] = a[i];
		L(i, x + 1, n - 1) {
			ll t = (1 << (i - x)), g = min(a[i], k / t);
			res += (t - 1) * g, k -= t * g, sum += t * g * ((1 << x) - 1), a[i] -= g;
		}
		// cout << res << endl;
		while(1) {
			if(sum >= k) {
				res += k;
				break;
			}
			int l = 0;
			L(i, x + 1, n - 1) if(a[i]) {
				l = i;
				break;
			}
			if(!l) {
				if(k > sum) assert(0);
				// cout << k << endl;
				res += k; 
				break;
			}
			// cout <<  "l = " << l << endl;
			a[l] --, res += l - x, k -= 2, sum += ((1 << x) - 1) * 2;
			L(i, x + 1, l - 1) a[i] ++;
			// if(k <= 0) cout << "WHYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY!\n";
			if(k <= 0) break;
			L(i, x + 1, n - 1) {
				ll t = (1 << (i - x)), g = min(a[i], k / t);
				res += (t - 1) * g, k -= t * g, sum += t * g * ((1 << x) - 1), a[i] -= g;
			}
			// cout << res << endl;
		}
		L(i, 0, n) a[i] = sav[i];
		printf("%lld\n", res);
	} 
	return 0;
}