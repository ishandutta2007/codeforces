#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct RMQ { //min range query (default)
	int n;
	vector<vector<T>> st;
	T cmb(T a, T b) { return max(a, b); }
	void init(vector<T> a) {
		n=a.size(), st={a};
		for (int i=1; (1<<i)<=n; ++i) {
			st.push_back(vector<T>(n-(1<<i)+1));
			for (int j=0; j+(1<<i)-1<n; ++j)
				st[i][j]=cmb(st[i-1][j], st[i-1][j+(1<<i-1)]);
		}
	}
	T qry(int l, int r) {
		int k = 31 - __builtin_clz(r-l+1);
		return cmb(st[k][l], st[k][r-(1<<k)+1]);
	}
};

const int mxN=2e5;
int n, m, ans[mxN];
ar<int, 3> rain[mxN];
ll cnt[mxN], pref[mxN];
ar<int, 2> seg[mxN];

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> rain[i][0] >> rain[i][1];
		rain[i][2]=i;
		cnt[i]=pref[i]=0;
	}
	sort(rain, rain+n);
	for (int i=0; i<n; ++i) {
		int j=lower_bound(rain, rain+n, ar<int, 3>{rain[i][0]-rain[i][1]+1})-rain;
		assert(j<=i&&rain[i][0]-rain[j][0]<rain[i][1]);
		pref[j]+=rain[i][1]-(rain[i][0]-rain[j][0]);
		++cnt[j];
		cnt[i]-=2;
		seg[i][0]=j;

		j=lower_bound(rain, rain+n, ar<int, 3>{rain[i][0]+rain[i][1]})-rain;
		assert(j>i);
		++cnt[j-1];
		if (j<n)
			pref[j]-=rain[i][1]-(rain[j-1][0]-rain[i][0]);
		seg[i][1]=j-1;
	}
	ll cur=0;
	for (int i=0; i<n; ++i) {
		if (i)
			pref[i]+=pref[i-1]+cur*(rain[i][0]-rain[i-1][0]);
		cur+=cnt[i];
	}
	RMQ<ll> r1, r2, r3;
	r1.init(vector<ll>(pref, pref+n));
	vector<ll> a(n), b(n);
	for (int i=0; i<n; ++i) {
		a[i]=pref[i]+rain[i][0];
		b[i]=pref[i]-rain[i][0];
	}
	r2.init(a);
	r3.init(b);
	for (int i=0; i<n; ++i) {
		if (seg[i][0]&&r1.qry(0, seg[i][0]-1)>m||seg[i][1]<n-1&&r1.qry(seg[i][1]+1, n-1)>m) {
			ans[rain[i][2]]=0;
			continue;
		}
		ans[rain[i][2]]=r3.qry(seg[i][0], i)+rain[i][0]-rain[i][1]<=m&&r2.qry(i, seg[i][1])-rain[i][0]-rain[i][1]<=m;
	}
	for (int i=0; i<n; ++i)
		cout << ans[i];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}