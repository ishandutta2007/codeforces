#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m;
//ar<int, 2> a[1e5], b[1e5]; //horizontal, vertical
vector<vector<int>> e;

struct BIT {
	int n;
	vector<int> bit;
	BIT(int _n) : n(_n+1) {bit.resize(n);}
	void upd(int i, int val) {for (++i; i<n; i+=i&-i) bit[i]+=val;}
	int sum(int i) {int res=0; for (++i; i>0; i-=i&-i) res+=bit[i]; return res;}
	int qry(int l, int r) {return sum(r)-sum(l-1);}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ll ans=1;
	for (int i=0; i<n; ++i) {
		int y, l, r; cin >> y >> l >> r;
		if (l==0&&r==1e6) ++ans;
		e.push_back({l, 1, y});
		e.push_back({r, 3, y});
	}
	for (int i=0; i<m; ++i) {
		int x, l, r; cin >> x >> l >> r;
		if (l==0&&r==1e6) ++ans;
		e.push_back({x, 2, l, r});
	}
	sort(e.begin(), e.end());
	/*for (auto x: e) {
		for (int i: x)
			cout << i << " ";
		cout << "\n";
	}*/
	BIT t(1e6+1);
	for (auto &x: e) {
		if (x[1]==1) {
			t.upd(x[2], 1);
		}
		if (x[1]==2) {
			ans+=t.qry(x[2], x[3]);
		}
		if (x[1]==3) {
			t.upd(x[2], -1);
		}
	}
	cout << ans << "\n";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/