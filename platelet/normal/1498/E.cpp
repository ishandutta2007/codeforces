#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define fi first
#define se second
#define mp make_pair

using namespace std;
const int N = 505;
typedef pair <int, int> P;
int n; P a[N];
int main() {
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i].fi), a[i].se = i;
	sort(a + 1, a + n + 1);
	int su = 0; P mi(n, 0), ma(-1, 0);
	pair <int, P> as;
	rep(i, 1, n) {
		su += a[i].fi;
		mi = min(mi, a[i]), ma = max(ma, a[i]);
		if(su == i * (i - 1) / 2) {
			if(mi.se ^ ma.se) as = max(as, mp(ma.fi - mi.fi, mp(mi.se, ma.se)));
			mi.fi = n, ma.fi = -1;
		}
	}
	if(as.se.fi) printf("! %d %d\n", as.se.fi, as.se.se);
	else puts("! 0 0");
	fflush(stdout);
	return 0;
}