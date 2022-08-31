#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7;
void exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= x * (a / b);
}
ll mul(ll aa, ll bb, ll mod) {
	ll sav = aa * bb - (ll)( (long db) aa * bb / mod + 0.2 ) * mod;
	return sav < 0 ? sav + mod : sav;
}
ll crt(ll *a, ll *b, int len) { // x mod a_i = b_i
	ll now = 1, ys = 0;
	L(i, 1, len) {
		ll g = __gcd(now, a[i]), c1, c2, md = a[i] / g;
		if((b[i] - ys) % g) return -1;
		exgcd(now, a[i], c1, c2), ((c1 %= md) += md) %= md, c1 = mul(c1, ((b[i] - ys) / g % md + md) % md, md);
		((c1 %= md) += md) %= md, ys += c1 * now;
		now /= g, now *= a[i], ((ys %= now) += now) %= now;
	}
	return ys;
}
ll A[N], B[N];
int n, tot, m, a[N], b[N], mp[N];
ll k, s[N];
void Main() {
	cin >> n >> m >> k;
	ll lcm = (ll) n * m / __gcd(n, m);
	L(i, 1, n) cin >> a[i], mp[a[i]] = i;
	A[1] = n, A[2] = m;	
	L(i, 1, m) {
		cin >> b[i];
		if(mp[b[i]]) {
			B[1] = mp[b[i]] % n, B[2] = i % m;
			ll pns = crt(A, B, 2);
			if(pns == -1) continue; 
			if(pns == 0) pns = lcm;
			s[++tot] = pns;
		}
	}
	sort(s + 1, s + tot + 1);
	ll g = lcm - tot, ans = ((k - 1) / g) * lcm, dd = k - ((k - 1) / g) * g;
	L(i, 1, tot) {
		if(dd < s[i]) break;
		dd ++;
	}
	cout << ans + dd << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}