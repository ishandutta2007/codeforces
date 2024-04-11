#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a, b, c, n;
vector<int> x, y;
ar<ll, 2> ans={0, 0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> n;
	for (int i=0; i<n; ++i) {
		int price; string type; cin >> price >> type;
		if (type[0]=='U') x.push_back(price);
		else y.push_back(price);
	}
	sort(x.rbegin(), x.rend());
	sort(y.rbegin(), y.rend());
	while(a>0&&!x.empty()) {++ans[0]; ans[1]+=x.back(); x.pop_back(); --a;}
	while(b>0&&!y.empty()) {++ans[0]; ans[1]+=y.back(); y.pop_back(); --b;}
	for (int i : y) x.push_back(i);
	sort(x.rbegin(), x.rend());
	while(c>0&&!x.empty()) {++ans[0]; ans[1]+=x.back(); x.pop_back(); --c;}
	cout << ans[0] << ' ' << ans[1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/