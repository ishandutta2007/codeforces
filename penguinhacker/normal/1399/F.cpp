#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	out << "[" << p.first << ", " << p.second;
	return out << "]\n";
}

const int mxN=3000;
int n, dp[2*mxN][2*mxN];
pair<int, int> seg[mxN];
vector<int> d, rs[2*mxN];

int calc(int l, int r) {
	if (dp[l][r]!=-1) return dp[l][r];
	int add=count(rs[l].begin(), rs[l].end(), r);
	if (l==r) return dp[l][r]=add;
	dp[l][r]=calc(l+1, r);
	for (int i: rs[l]) {
		if (i>=r) continue;
		dp[l][r]=max(dp[l][r], calc(l, i)+calc(i+1, r));
	}
	return dp[l][r]=dp[l][r]+add;
}

void test_case() {
	cin >> n;
	d.clear();
	for (int i=0; i<n; ++i) {
		int a, b; cin >> a >> b;
		d.push_back(a);
		d.push_back(b);
		seg[i]={a, b};
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<d.size(); ++i)
		rs[i].clear();
	for (int i=0; i<n; ++i) {
		seg[i].first=lower_bound(d.begin(), d.end(), seg[i].first)-d.begin();
		seg[i].second=lower_bound(d.begin(), d.end(), seg[i].second)-d.begin();
		rs[seg[i].first].push_back(seg[i].second);
		//cout << seg[i];
	}
	for (int i=0; i<d.size(); ++i) {
		//sort(rs[i].begin(), rs[i].end());
		//cout << i << ": ";
		//for (int j: rs[i]) cout << j << ' ';
		//cout << '\n';
		fill(dp[i]+i, dp[i]+(int)d.size(), -1);
	}
	//calc(0, d.size()-1);
	/*for (int i=0; i<d.size(); ++i) {
		for (int j=i; j<d.size(); ++j)
			cout << "[" << i << ", " << j << "] = " << dp[i][j] << '\n';
		cout << '\n';
	}*/
	cout << calc(0, d.size()-1) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/