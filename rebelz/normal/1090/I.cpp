#include <bits/stdc++.h>
#define il inline
#define ri register int
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 20000050
#define MAXM
#define MOD
#define INF (1<<25)
#define LLINF (9223372036854775807LL)
#define eps (1e-6)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;
typedef pair <LL, int> pli;
typedef pair <int, LL> pil;
typedef pair <LL, LL> pll;
int t, n, a[MAXN], pos;
LL b1, b2, ans, l, r, x, y, z;
bool check1() {
	for(ri i = 1; i <= n; ++i) if(a[i] < 0) return 0;
	return 1;
}
bool check2() {
	for(ri i = 1; i <= n; ++i) if(a[i] > 0) return 0;
	return 1;
}
bool check3() {
	pos = 0; int f = 0;
	for(ri i = 1; i <= n; ++i) {
		if(a[i] < 0 && !pos) pos = i-1, f = 1;
		if(a[i] > 0 && f) return 0;
	}
	return 1;
}
void rev(int l, int r) {
	reverse(a+l, a+r+1);
	for(ri i = l; i <= r; ++i) a[i] = a[i] * -1;
}
LL solve(int l, int r) {
	int minn = 2e9+5; LL res = LLINF;
	for(ri i = l; i <= r; ++i) {
		if(minn < a[i]) res = min(res, 1ll*a[i]*minn);
		minn = min(minn, a[i]);
	}
	return res;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &n, &l, &r, &x, &y, &z, &b1, &b2);
		a[1] = b1%(r-l+1)+l, a[2] = b2%(r-l+1)+l;
		for(ri i = 3; i <= n; ++i) {
			LL b3 = (1ull*b1*x + 1ull*b2*y + z) % (1LL<<32);
			a[i] = b3%(r-l+1)+l;
			b1 = b2, b2 = b3;
		}
		if(check1()) ans = solve(1, n);
		else if(check2()) rev(1, n), ans = solve(1, n);
		else if(check3()) rev(pos+1, n), ans = min(solve(1, pos), solve(pos+1, n));
		else ans = solve(1, n);
		if(ans >= LLINF) cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}