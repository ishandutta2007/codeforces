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

int n;
int c[2][110];

ll Eval(int r, int pick) {
	ll ans = 0;
	for (int i=100; 0<=i; --i) {
		ll t = min(pick, c[r][i]);
		pick -= t;
		ans += t*i;
	}
	return ans;
}

bool ok(int plus) {
	int picks = n+plus-(n+plus)/4;

	c[0][100] += plus;
	ll hi = Eval(0, picks);
	c[0][100] -= plus;

	c[1][0] += plus;
	ll lo = Eval(1, picks);
	c[1][0] -= plus;

	return hi >= lo;
}

void Work() {
	cin >> n;
	memset(c, 0, sizeof(c));
	rep(i, 2) rep(j, n) { int x; cin >> x; ++c[i][x]; }

	int l = -1, r = int(1e6);
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (ok(mid)) r = mid;
		else l = mid;
	}

	cout << r << '\n';
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}