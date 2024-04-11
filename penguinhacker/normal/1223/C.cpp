#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p[200000];
ll x, y, a, b, c, k;

bool ok(int f) {
	vector<int> cnt(3);
	for (int i=1; i<=f; ++i) {
		if (i%c==0) cnt[0]++;
		else if (i%a==0) cnt[1]++;
		else if (i%b==0) cnt[2]++;
	}
	int ind=0;
	ll sum=0;
	while(cnt[0]>0) {--cnt[0]; sum+=(x+y)*p[ind++];}
	while(cnt[1]>0) {--cnt[1]; sum+=(x)*p[ind++];}
	while(cnt[2]>0) {--cnt[2]; sum+=(y)*p[ind++];}
	return sum>=k;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> p[i], p[i]/=100;
	sort(p, p+n, greater<int>());
	cin >> x >> a >> y >> b >> k; //x>y
	if (x<y) {
		swap(x, y);
		swap(a, b);
	}
	c=a*b/__gcd(a, b);
	//cout << a << ' ' << b << ' ' << c << '\n';
	if (!ok(n)) {cout << "-1\n"; return; }
	int l=1, r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if (ok(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout << l << '\n';
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