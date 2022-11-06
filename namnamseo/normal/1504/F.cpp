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

const int maxn = int(4e5) + 10;

struct card { int x, y, f; } d[maxn];

int n;
bool flg[maxn];

void die() { cout << "-1\n"; exit(0); }

int get_lis(vector<int> &yv) {
	if (yv.empty()) return 0;
	static int lis[maxn], ln;
	lis[ln = 1] = 0;
	for (int i=1, s=sz(yv); i<s; ++i) {
		int j = lower_bound(lis+1, lis+ln+1, i,
		[&](const int &a, const int &b) {
			return yv[a] < yv[b];
		}) - lis;
		lis[j] = i;
		if (j > ln) ++ln;
	}

	return ln;
}

int main()
{
	cppio();
	cin >> n;

	rrep(i, n) {
		int x, y; cin >> x >> y;
		int flag = 0;
		if (x > y) { swap(x, y); flag = 1; }
		if (y <= n) die();
		if (d[x].y) die();
		d[x] = {x, y, flag};
	}

	{
		vector<int> yv;
		rrep(i, n) yv.pb(d[i].y);
		if (get_lis(yv) >= 3) die();
	}

	static int pmx[maxn];
	static int pmn[maxn];

	{ int mn = 2*n+1;
	rrep(i, n) {
		if (d[i].y < mn) mn = d[i].y;
		pmn[i] = mn;
	} }

	{ int mx = -1;
	for (int i=n; 1<=i; --i) {
		if (d[i].y > mx) mx = d[i].y;
		pmx[i] = mx;
	} }

	int ans = n;
	auto Work = [&](int l, int r) {
		if (l > r) return;
		int fc[2] = {0, 0};
		int mny = (l == 1 ? (2*n+1) : (d[l-1].y));
		for (int i=l; i<=r; ++i) {
			++fc[(mny > d[i].y) == (d[i].f == 1)];
			mny = min(mny, d[i].y);
		}
		ans -= max(fc[0], fc[1]);
	};

	for (int i=1, li=0; i<=n; ++i) {
		if (pmn[i] > pmx[i+1]) {
			Work(li+1, i);
			li = i;
		}
		if (i == n) Work(li+1, i);
	}

	cout << ans << '\n';

	return 0;
}