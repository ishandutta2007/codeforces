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

pp d[maxn];

vector<int> vs;

int ps[maxn];

int f(int v) {
	return lower_bound(all(vs), v) - vs.begin();
}

int main()
{
	cppio();

	int n;
	cin >> n;
	rrep(i, n) {
		int a, c; cin >> a >> c;
		d[i] = {a, a+c};
	}

	rrep(i, n) vs.pb(d[i].x), vs.pb(d[i].y);
	sort(all(vs));
	vs.erase(unique(all(vs)), vs.end());

	rrep(i, n) {
		int x, y; tie(x, y) = d[i];
		x = f(x);
		y = f(y);
		++ps[x];
		--ps[y];
	}

	ll ans = 0;
	rrep(i, n) ans += d[i].y - d[i].x;
	for (int i=0; i+1 < sz(vs); ++i) {
		ps[i+1] += ps[i];
		ll v = ps[i];
		if (!v) ans += (vs[i+1] - vs[i]);
	}

	cout << ans << '\n';

	return 0;
}