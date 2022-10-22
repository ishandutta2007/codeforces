#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, T, x, y, cnt[2];
ar<int, 2> a[200000];

int calc(int left) {
	if (left<=0) return 0;
	if (1ll*cnt[0]*x>=left)
		return left/x;
	left-=cnt[0]*x;
	if (1ll*cnt[1]*y>=left)
		return cnt[0]+left/y;
	return cnt[0]+cnt[1];
}

void solve() {
	cin >> n >> T >> x >> y;
	cnt[0]=cnt[1]=0;
	for (int i=0; i<n; ++i)
		cin >> a[i][1], ++cnt[a[i][1]];
	for (int i=0; i<n; ++i)
		cin >> a[i][0];
	sort(a, a+n);
	ll need=0;
	int ans=calc(a[0][0]-1);
	for (int i=0; i<n; ++i) {
		--cnt[a[i][1]];
		need+=a[i][1]?y:x;
		ll upTo=(i==n-1?T:a[i+1][0]-1)-need;
		if (upTo<0||(i<n-1&&a[i][0]==a[i+1][0]))
			continue;
		int cur=i+1+calc(upTo);
		ans=max(ans, cur);
	}
	cout << ans << "\n";
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