#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string pin[10];

bool same(int x) {
	for (int i=0; i<n; ++i)
		if (x!=i&&pin[i]==pin[x])
			return 1;
	return 0;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> pin[i];
	int ans=0;
	for (int i=0; i<n; ++i) {
		if (!same(i))
			continue;
		++ans;
		for (int j=0; j<10; ++j) {
			pin[i].pop_back();
			pin[i].push_back(j+'0');
			if (!same(i))
				break;
		}
	}
	cout << ans << '\n';
	for (int i=0; i<n; ++i)
		cout << pin[i] << '\n';
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