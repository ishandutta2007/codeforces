#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 100010, inf = 0x3f3f3f3f;
typedef long long ll;

int n, M, P[N], I[N];
int add(int x, int y) {return x + y >= M ? x + y - M : x + y;}
int sub(int x, int y) {return x < y ? x - y + M : x - y;}
int mul(int x, int y) {return 1ll * x * y % M;}
int exgcd(ll a, ll b, ll &x, ll &y) {return (b == 0 ? (x = 1, y = 0) : (exgcd(b, a % b, y, x), y -= (a / b) * x));}
int Inv(int a) {ll x, y; exgcd(a, M, x, y);return (x % M + M) % M;}
int Pow(int x, int y) {int ret = 1;while (y) {if (y & 1) ret = mul(ret, x);x = mul(x, x), y >>= 1;}return ret;}

vector <pii > G[N];

int Mf, rt = 0, f[N], siz[N], vis[N];

void get_R(int x, int fa, int S) {
	siz[x] = 1; int Ma = 0;
	for (pii i : G[x]) if (i.fi != fa && !vis[i.fi]) {
		get_R(i.fi, x, S), siz[x] += siz[i.fi];
		Ma = max(Ma, siz[i.fi]);
	}
	Ma = max(Ma, S - siz[x]);
	if (Ma < Mf) Mf = Ma, rt = x;
}

map <int, ll> ton; pii temp[N]; int cnt = 0;

void getD(int x, int fa, ll d1, ll d2, int dep) {
	if (dep >= 0) ++ton[d1], temp[++cnt] = mp(d2, dep);
	for (pii i : G[x]) if (i.fi != fa && !vis[i.fi])
		getD(i.fi, x, add(d1, mul(P[dep + 1], i.se % M)), add(mul(d2, 10), i.se % M), dep + 1);
}

ll calc(int x, int d) {
	ll ans = 0; ton.clear(); cnt = 0;
	if (d) getD(x, 0, d % M, d % M, 0);
	else getD(x, 0, 0, 0, -1);
	for (int i = 1; i <= cnt; i++) {
		ll tmp = sub(0, mul(temp[i].fi, I[temp[i].se + 1]));
		if (ton.find(tmp) != ton.end()) ans += ton[tmp];
		if (!d) ans += (temp[i].fi == 0);
	}
	if (!d) ans += ton[0];
	return ans;
}

ll Ans = 0;

void get_Ans(int x) {
	Ans += calc(x, 0), vis[x] = 1;
	for (pii i : G[x]) if (!vis[i.fi]) {
		Ans -= calc(i.fi, i.se);
		Mf = inf, get_R(i.fi, 0, siz[i.fi]), get_Ans(rt);
	}
}

int main() {
	scanf("%d%d", &n, &M);
	P[0] = I[0] = 1;
	for (int i = 1; i <= n; i++)
		P[i] = mul(P[i - 1], 10), I[i] = Inv(P[i]);
	for (int i = 1; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w), x++, y++;
		G[x].pb(mp(y, w)), G[y].pb(mp(x, w));
	}
	Mf = inf, get_R(1, 0, n), get_Ans(rt);
	printf("%lld\n", Ans);
	return 0;
}