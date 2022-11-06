#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;

#define point pair<int>
#define x first
#define y second

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	int s; cin >> s;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	vector<int> b(n); for (int o = 0; o < n; o++) { cin >> b[o]; }
	std::vector<pair<int, int>> t1;
	std::vector<pair<int, int>> t2;
	t1.pb({0, -1});
	t2.pb({0, -1});
	for (int i = 0; i < m; ++i) {
		int ti; cin >> ti;
		int ci; cin >> ci;
		if (ti == 1) {
			t1.pb({ci, i});
		} else {
			t2.pb({ci, i});
		}
	}
	sort(t1.begin(), t1.end()); 
	sort(t2.begin(), t2.end()); 
	for (int i = 1; i < t1.size(); ++i) {
		t1[i].first += t1[i - 1].first;
	}  
	for (int i = 1; i < t2.size(); ++i) {
		t2[i].first += t2[i - 1].first;
	} 
	int t2size = t2.size();
	t2size--;
	std::vector< pair<pair<int, int>, int> > v;
	for (int i = max(k - t2size, 0ll); i <= min(k, (int)(t1.size()) - 1ll); ++i) {
		v.pb({{t1[i].first, t2[k - i].first}, i});
	}
	int vs = v.size();
	int m1 = 1000000000000000ll, m2 = 100000000000000ll;
	int d1 = -1, d2 = -1;
	for (int i = 0; i < n; ++i) {
		if (m1 > a[i]) {
			m1 = a[i];
			d1 = i;
		} 
		if (m2 > b[i]) {
			m2 = b[i];
			d2 = i;
		}
		//search 
		int l = 0, r = vs - 2;
		while (l < r) {
			int m = (r + l) >> 1ll;
			if (m < 0) {
				r = l;
				continue;
			}
			int c1 = v[m].x.x;
			int c2 = v[m].x.y;
			int c11 = v[m + 1].x.x;
			int c12 = v[m + 1].x.y;
			int tc = c1 * m1 + c2 * m2;
			int tc1 = c11 * m1 + c12 * m2;
			if (tc <= tc1) {
				r = m;
			} else {
				l = m + 1;
			}
		} 
		if (l >= 0 && l < vs) {
			int c1 = v[l].x.x;
			int c2 = v[l].x.y;
			int c11 = v[vs - 1].x.x;
			int c12 = v[vs - 1].x.y;
			int tc = c1 * m1 + c2 * m2;
			int tc1 = c11 * m1 + c12 * m2;
			if (tc1 < tc)
				l = vs - 1;
		} 
			
		if (l >= 0 && l < vs && (v[l].x.x * m1 + v[l].x.y * m2 <= s)) {
			cout << i + 1 << "\n";
			int uu = v[l].y;
			for (int j = 1; j <= uu; ++j) {
				cout << t1[j].y + 1 << " " << d1 + 1 << "\n";
			} 
			for (int j = 1; j <= (k - uu); ++j)  {
				cout << t2[j].y + 1 << " " << d2 + 1 << "\n";
			}
			return 0;
		} 
	}
	cout << -1;
}