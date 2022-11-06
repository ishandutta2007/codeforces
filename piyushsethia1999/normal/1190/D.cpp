#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

const int MAXN = 600000;

int seg[MAXN];
const int N = 300000;

void build() {
	for (int i = N - 1; i > 0; --i) seg[i] = seg[i << 1] + seg[(i << 1) | 1];
}

void update(int i, int val) {
	for(seg[i += N] = val; i > 1; i >>= 1) seg[i >> 1] = seg[i] + seg[i ^ 1];
}

int query(int l, int r) {
	if (r < l) return 0;
	r++; int a = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (r & 1) a += seg[--r];
		if (l & 1) a += seg[l++];
	}
	return a;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vector<pair<int, int> > p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].se >> p[i].fi;
	p.pb(-1, -1);

	std::map<int, int> com;
	std::vector<int> f(n);
	for (int i = 0; i < n; ++i) f[i] = p[i].se;
	sort(f.begin(), f.end());
	auto enen = unique(f.begin(), f.end());
	int temptemp = 0;
	for (auto i = f.begin(); i != enen; ++i) com[*i] = temptemp++;
	for (int i = 0; i < n; ++i) p[i].se = com[p[i].se];
	sort(p.begin(), p.end(), greater<pair<int, int> >());


	set<int> s; int si = 1;
	int ans = 0;
	for (int i = 0; i < n; ) {
		int su = 0; 
		int sqsu = 0;
		int las = 250000;
		int j = i;
		while (p[j].fi == p[i].fi) {
			int uu = query(p[j].se + 1, las) + 1;			
			las = p[j].se - 1;
			su += uu;
			sqsu += (uu * uu);
			update(p[j].se, 1);
			j++;
		}
		int uu = query(0, las) + 1;			
		su += uu;
		sqsu += (uu * uu);
		i = j;
		ans = (ans + (su * su - sqsu) / 2ll);
	}
	cout << ans;
}