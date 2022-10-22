#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, h, m, k, a[mxN];
map<int, int> mp;
vector<ar<int, 2>> v;
ar<int, 2> ans={696969, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h >> m >> k, m/=2;
	for (int i=0; i<n; ++i) {
		cin >> a[i] >> a[i], a[i]%=m;
		++mp[a[i]];
	}
	for (int i=0; i<2; ++i)
		for (auto& x : mp)
			v.push_back({x.first+i*m, x.second});
	for (int i=0, j=1, cur=0; v[i][0]<m; ++i) {
		while(v[j][0]<v[i][0]+k)
			cur+=v[j++][1];
		ans=min(ans, {cur, v[i][0]});
		cur-=v[i+1][1];
	}
	cout << ans[0] << " " << (ans[1]+k)%m << "\n";
	for (int i=0; i<n; ++i) {
		int l=ans[1], r=ans[1]+k;
		if (l<a[i]&&a[i]<r||l<a[i]+m&&a[i]+m<r)
			cout << i+1 << " ";
	}
	return 0;
}