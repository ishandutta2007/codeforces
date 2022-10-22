#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int a,b,c,r;

void solve() {
	cin >> a >> b >> c >> r;
	if (a>b)
		swap(a,b);
	int ans = b-a;
	if (c<=a) {
		if (c+r>=b)
			ans=0;
		else
			ans -= max(0,c+r-a);
	}
	else if (c>=b) {
		if (c-r<=a)
			ans=0;
		else
			ans -= max(0,b-(c-r));
	}
	else {
		ans -= min(r,b-c);
		ans -= min(r, c-a);
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