#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	vector<int> d(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());

	vector<vector<int>> oc(d.size());
	for (int i=0; i<n; ++i) {
		a[i]=lower_bound(d.begin(), d.end(), a[i])-d.begin();
		oc[a[i]].push_back(i);
	}

	auto calc=[&](vector<int> &v) {
		int cur=0;
		for (int i: v)
			cur+=oc[i].size();
		int l=v[0], r=v.back();
		if (l>0)
			for (int i: oc[l-1])
				if (i<oc[l][0]) ++cur;
		if (r+1<d.size())
			for (int i: oc[r+1])
				if (i>oc[r].back()) ++cur;
		//cout << "cur: " << cur << "\n";
		return cur;
	};

	int ans=n;
	for (int i=0, j; i<d.size(); i=j) {
		vector<int> cur={i};
		for (j=i+1; j<d.size(); ++j) {
			if (oc[j][0]>oc[j-1].back())
				cur.push_back(j);
			else
				break;
		}
		ans=min(ans, n-calc(cur));
	}
	for (int i=0; i+1<d.size(); ++i) {
		vector<int> v(oc[i].size()+oc[i+1].size());
		merge(oc[i].begin(), oc[i].end(), oc[i+1].begin(), oc[i+1].end(), v.begin());
		int cnt0=0, cnt1=0;
		for (int &j: v) {
			j=a[j]-i;
			assert(j==0||j==1);
			if (j==1) ++cnt1;
		}
		//010001000111
		int cur=cnt1;
		for (int j: v) {
			if (j==0) ++cnt0;
			else --cnt1;
			cur=max(cur, cnt0+cnt1);
		}
		ans=min(ans, n-cur);
	}
	cout << ans << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/