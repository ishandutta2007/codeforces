#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[2000];
vector<int> o, e;

void solve() {
	cin >> n;
	o.clear(), e.clear();
	for (int i=0; i<2*n; ++i) {
		cin >> a[i];
		if (a[i]%2==0)
			e.push_back(i+1);
		else
			o.push_back(i+1);
	}
	for (int i=0; i<e.size()/2&&i<n-1; ++i)
		cout << e[2*i] << ' ' << e[2*i+1] << '\n';
	for (int i=e.size()/2; i<n-1; ++i)
		cout << o[2*(i-e.size()/2)] << ' ' << o[2*(i-e.size()/2)+1] << '\n';
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