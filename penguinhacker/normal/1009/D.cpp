#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
vector<pair<int, int>> ans;

int gcd(int a, int b) {
	if (a<b)
		swap(a, b);
	if (a%b==0)
		return b;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	if (m<n-1) {
		cout << "Impossible";
		return 0;
	}
	for (int i=1; i<n; ++i) {
		bool check=1;
		for (int j=i+1; j<=n; ++j) {
			if (gcd(i, j)!=1)
				continue;
			ans.emplace_back(i, j);
			if (ans.size()==m) {
				check=0;
				break;
			}
		}
		if (!check)
			break;
	}
	if (ans.size()<m) {
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for (auto x : ans)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/