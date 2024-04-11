#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
ll p[100000];
pair<ll, ll> a[100000];

ll get(int k) { //get k largest
	return p[m-1]-(k==m?0:p[m-1-k]);
}
void solve() {
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a+m);
	for (int i=0; i<m; ++i)
		p[i]=a[i].first+(i?p[i-1]:0);
	ll ans=get(min(n, m));
	for (int i=0; i<m; ++i) {
		int take=lower_bound(a, a+m, make_pair(a[i].second, -1ll))-a;
		take=m-take;
		int left=n-take-(a[i].first<a[i].second);
		if (left<=0) continue;
		ans=max(ans, get(take)+(a[i].first<a[i].second?a[i].first:0)+left*a[i].second);
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