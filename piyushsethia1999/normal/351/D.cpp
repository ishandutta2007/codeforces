#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int bl = 500;

struct Query
{
	int l, r, i;
	const bool operator<(const Query& a) {
		return (((l / bl) < (a.l / bl)) || ((l / bl) == (a.l / bl) && r < a.r));	 
	}
};

struct Pair { int l, m, r; 
	Pair(int l, int m, int r) : l(l), r(r), m(m) {}
};

int freq[100005] = {};
int a[100005];
int c[100005];
int b[100005];
int isoutsync[100005] = {};
int to = 0;
deque<Pair> q[100005];
int le[100005] = {};
int ri[100005] = {};

int total = 0;

void add(int i, bool isleft) {
	if (!(freq[a[i]]++)) total++;
	if (freq[a[i]] >= 3) {
		if (!isleft) {
			int ap = c[i] - c[c[i]];
			int bp = i - c[i];
			if (ap != bp) q[a[i]].push_back({c[c[i]], c[i], i});
		}
		else {
			int ap = b[i] - i;
			int bp = b[b[i]] - b[i];
			if (ap != bp) q[a[i]].push_front({i, b[i], b[b[i]]});
		}
		if (!isoutsync[a[i]]) { 
			isoutsync[a[i]] = (!q[a[i]].empty());
			if (isoutsync[a[i]]) to++;
		}
	} 
}

void rem(int i, bool isleft) {
	if (!(--freq[a[i]])) total--;
	if (freq[a[i]] >= 2) {
		if (!isleft) {
			int ap = c[i] - c[c[i]];
			int bp = i - c[i];
			if (ap != bp) q[a[i]].pop_back();
		}
		else {
			int ap = b[i] - i;
			int bp = b[b[i]] - b[i];
			if (ap != bp) q[a[i]].pop_front();
		}
		if (isoutsync[a[i]]) { 
			isoutsync[a[i]] = (!q[a[i]].empty());
			if (!isoutsync[a[i]]) to--;
		}
	}
}

int answer(Query q) {
	if (to == total) 
		return (total + 1);
	return total;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	for (int o = 0; o < n; o++) { cin >> a[o]; }
	int rr[n], ll[n];
	memset(ll, -1, sizeof(ll));
	memset(rr, -1, sizeof(rr));
	for (int i = 0; i < n; ++i) {
		c[i] = ll[a[i]];
		ll[a[i]] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		b[i] = rr[a[i]];
		rr[a[i]] = i;
	}
	int q; cin >> q;
	std::vector<Query> v(q);
	for (int i = 0; i < q; v[i].l--, v[i].r--, ++i) cin >> v[i].l >> v[i].r, v[i].i = i;
	sort(v.begin(), v.end());
	int l = 0, r = -1;
	int ans[100004];
	for (int i = 0; i < q; ++i) 
	{
		while (r < v[i].r) add(++r, false); 
		while (l > v[i].l) add(--l, true); 
		while (r > v[i].r) rem(r--, false); 
		while (l < v[i].l) rem(l++, true); 
		ans[v[i].i] = answer(v[i]);
	}
	for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
}