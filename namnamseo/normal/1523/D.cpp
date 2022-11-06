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

int n, m, p;
int nt, nnt;
ll d[maxn];

ll In() { static char buf[100]; cin >> buf; ll ret = 0; for (int i=0; i<m; ++i) ret = (ret*2) + (buf[i]-'0'); return ret; }

ll ans, ac; void upd_ans(ll v) { int t = __builtin_popcountll(v); if (ac < t) { ans = v; ac = t; } }

const int pck = 15;
int mp[pck];
int bc[100];

int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	cppio();
	cin >> n >> m >> p; rep(i, n) d[i] = In(); nt = (n+1)/2; nnt = n - nt;
	ac = 0;
	rep(i, n) rep(j, m) if (1&(d[i]>>j)) ++bc[j];

	int stg = 0;
rep(stg, 1000) {
	ll v = ((1ll<<m)-1);

	{
		int hm = uniform_int_distribution<int>(1, 6)(rng);
		hm = max(1, min(n, hm));
		rep(i, hm) v &= d[uniform_int_distribution<int>(0, n-1)(rng)];
	}

	static int ubs[100], ubn; ubn = 0;
	rep(i, m) if (1&(v>>i)) ubs[ubn++] = i;
	sort(ubs, ubs+ubn, [&](const int& a, const int& b) {
		return bc[a] < bc[b]; });
	int ubi = 0;

	while (true) {
		if (__builtin_popcountll(v) <= ac) break;

		int ac = 0, no = 0;

		rep(i, n) {
			if ((v&d[i]) == v) ++ac;
			else ++no;
			if (no > nnt) break;
		}

		if (ac >= nt) {
			upd_ans(v);
			break;
		}
		v &= (~(1ll << ubs[ubi++]));
	}
}

	for (int i=0; i<m; ++i) {
		int b = (ans >> (m-1-i)) & 1;
		cout << b;
	}
	cout << '\n';

	return 0;
}