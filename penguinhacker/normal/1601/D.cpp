#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5, INF=1e9;
int n, sd, cnt[2*mxN+1], dp[2*mxN+1], ft[2*mxN+2];
ar<int, 2> a[mxN];
vector<int> d;
ar<int, 3> e[mxN];
vector<ar<int, 2>> trans[2*mxN+1];

void upd(int i) {
	for (++i; i<=d.size(); i+=i&-i)
		++ft[i];
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> sd;
	d.push_back(sd);
	for (int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1];
		d.push_back(a[i][0]);
		d.push_back(a[i][1]);
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	sd=lower_bound(d.begin(), d.end(), sd)-d.begin();
	for (int i=0; i<n; ++i) {
		a[i][0]=lower_bound(d.begin(), d.end(), a[i][0])-d.begin();
		a[i][1]=lower_bound(d.begin(), d.end(), a[i][1])-d.begin();
		if (a[i][1]<=a[i][0]) {
			++cnt[a[i][1]];
			e[i]={a[i][0], 1, a[i][1]};
			dp[sd]+=a[i][0]>=sd&&a[i][1]<=sd;
		} else {
			e[i]={a[i][1], 0, a[i][0]};
		}
	}
	sort(e, e+n);
	for (int i=n-1; ~i; --i) {
		if (e[i][1]==1) {
			upd(e[i][2]);
		} else {
			int x=qry(e[i][0])-qry(e[i][2]);
			trans[e[i][2]].push_back({e[i][0], x+1});
		}
	}
	for (int i=sd; i<d.size(); ++i) {
		dp[i]=max(dp[i], (i?dp[i-1]:0)+cnt[i]);
		for (auto [j, x] : trans[i])
			dp[j]=max(dp[j], dp[i]+x);
		//cout << i << " " << dp[i] << endl;
	}
	cout << dp[d.size()-1];
	return 0;
}