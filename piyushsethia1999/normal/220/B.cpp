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

int freq[100005] = {};

int total = 0;
std::vector<int> a;
std::vector<int> b;

void add(int i, bool isleft) {
	if (freq[a[i]] == b[a[i]]) total--; 
	freq[a[i]]++;
	if (freq[a[i]] == b[a[i]]) total++; 
}

void rem(int i, bool isleft) {
	if (freq[a[i]] == b[a[i]]) total--; 
	freq[a[i]]--;
	if (freq[a[i]] == b[a[i]]) total++;	
}

int answer(Query q) {
	return total;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int q; cin >> q;
	a.resize(n);
	b.resize(n);
	for (int o = 0; o < n; o++) { cin >> a[o]; b[o] = a[o]; }
	std::map<int, int> com;
	sort(b.begin(), b.end());
	auto en = unique(b.begin(), b.end());
	int y = 0;
	for (auto it = b.begin(); it != en; ++it) com[*it] = y++;
	for (int i = 0; i < n; ++i) a[i] = com[a[i]];
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