#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Point {
	ll x, y;
	Point operator-(const Point& o) const {
		return {x-o.x, y-o.y};
	}
	ll operator*(const Point& o) const {
		return x*o.y-y*o.x;
	}
};

const int mxN=1e5;
int n, q, last[3*mxN], ans[mxN];
vector<pair<Point, int>> all;
vector<int> e[mxN];
vector<ar<int, 2>> qry[mxN];

struct {
	int ft[mxN+1];
	void upd(int i, int x) {
		for (++i; i<=n; i+=i&-i)
			ft[i]+=x;
	}
	int qry(int i) {
		int r=0;
		for (++i; i; i-=i&-i)
			r+=ft[i];
		return r;
	}
} ft;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int k;
		cin >> k;
		vector<Point> v(k);
		for (Point& p : v)
			cin >> p.x >> p.y;
		for (int j=0; j<k; ++j)
			all.push_back({v[(j+1)%k]-v[j], i});
	}
	sort(all.begin(), all.end(), [&](const pair<Point, int>& a, const pair<Point, int>& b) {
		int qa=a.first.y<0||a.first.x<0&&a.first.y==0;
		int qb=b.first.y<0||b.first.x<0&&b.first.y==0;
		return qa^qb?qa<qb:a.first*b.first>0;
	});
	int cur=0;
	for (int i=0; i<all.size(); ++i) {
		if (i&&all[i].first*all[i-1].first)
			++cur;
		e[all[i].second].push_back(cur);
	}
	cin >> q;
	for (int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		qry[r].push_back({l, i});
	}
	memset(last, -1, 4*(cur+1));
	for (int i=0; i<n; ++i) {
		ft.upd(i, e[i].size());
		for (int j : e[i]) {
			//cout << j << " ";
			if (last[j]!=-1)
				ft.upd(last[j], -1);
			last[j]=i;
		}
		//cout << "\n";
		for (ar<int, 2> x : qry[i])
			ans[x[1]]=ft.qry(i)-ft.qry(x[0]-1);
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << "\n";
	return 0;
}