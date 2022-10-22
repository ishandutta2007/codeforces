#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

double c, h, g;

double cmp(int x) {
	return x*h/(2*x-1);
}

void solve() {
	cin >> h >> c >> g, h-=c, g-=c;
	if (g<=h/2) {cout << 2 << '\n'; return;}
	if (g>=h) {cout << 1 << '\n'; return;}
	int l=1, r=10000000;
	while(l<r) {
		int mid=(l+r)/2;
		//cout << mid << ' ' << cmp(mid) << '\n';
		if (cmp(mid)<g)
			r=mid;
		else
			l=mid+1;
	}
	cout << (g-cmp(l)<cmp(l-1)-g?2*l-1:2*l-3) << '\n';
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