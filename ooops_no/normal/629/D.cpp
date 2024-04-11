#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double
#define ll long long

const int N = 1e5 + 10;
const long double PI = acos(-1.0);
ld t[4 * N];

bool cmp(const pair<ld, int>&a,  const pair<ld, int>&b){
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

void update(int v, int l, int r, int pos, int val) {
	if (l == r) {
		t[v] = val;
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m) {
		update(2 * v, l, m, pos, val);
	}
	else {
		update(2 * v + 1, m + 1, r, pos, val);
	}
	t[v] = max(t[v * 2 + 1], t[v * 2]);
}

ld mx(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (tl == l && tr == r) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return max(mx(2 * v, tl, tm, l, min(r, tm)), mx(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<ld, int> ind;
	vector<pair<ld, int>> v;
	vector<ld> a;
	for (int i = 0; i < n; i++) {
		ld a1, b;
		cin >> a1 >> b;
		v.pb({ a1 * a1 * b, i });
		a.pb(a1 * a1 * b);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		ind[v[i].second] = i;
	}
	ld ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ld lol = mx(1, 0, N - 1, 0, ind[i]) + a[i];
		ans = max(ans, lol);
		update(1, 0, N - 1, ind[i], lol);
	}
	cout << setprecision(6) << fixed << ans * PI;
	return 0;
}