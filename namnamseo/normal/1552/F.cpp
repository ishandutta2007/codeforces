#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;
const int mod = 998'244'353;

int n;

struct Tele {
	int x, y, s;
} d[maxn];

int fen[maxn*2];
int xp[maxn*2], xpn;

void Comp() {
	rrep(i, n) xp[xpn++]=d[i].x, xp[xpn++]=d[i].y;
	sort(xp, xp+xpn);
	xpn = unique(xp, xp+xpn) - xp;
}

int Conv(int x) { return int(lower_bound(xp, xp+xpn, x) - xp) + 1; }

void Z(int &x) {
	if (x >= mod) x -= mod;
}

int Sum(int p) {
	int ret = 0;
	while (p) ret += fen[p], Z(ret), (p &= (p-1));
	return ret;
}

void Upd(int p, int v) {
	for (; p <= xpn; p += (p&(-p))) {
		fen[p] += v;
		Z(fen[p]);
	}
}

int uses[maxn];

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> d[i].y >> d[i].x >> d[i].s;
//	sort(d+1, d+n+1, [&](const pp& a, const pp& b) { return a.y < b.y; });

	Comp();

	for (int i=n; 1<=i; --i) {
		uses[i] = Sum(Conv(d[i].y)-1);
		if (d[i].s == 1) ++uses[i];
		Z(uses[i]);
		Upd(Conv(d[i].x), uses[i]);
	}

	int ans = d[n].y+1;
	Z(ans);
	rrep(i, n) {
		ll t = (d[i].y - d[i].x);
		t %= mod;
		t *= uses[i];
		t %= mod;

		ans += t;
		Z(ans);
	}

	cout << ans << '\n';

	return 0;
}