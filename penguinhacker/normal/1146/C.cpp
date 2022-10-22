#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans;

void qry(int k) {
	vector<int> v1, v2;
	for (int i=1; i<=n; ++i) {
		int x=i%(2*k);
		if (0<=x&&x<k)
			v1.push_back(i);
		else
			v2.push_back(i);
	}
	if (v1.empty()||v2.empty())
		return;
	cout << v1.size() << ' ' << v2.size() << ' ';
	for (int i : v1)
		cout << i << ' ';
	for (int i : v2)
		cout << i << ' ';
	cout << '\n';
	cout.flush();
	int d;
	cin >> d;
	if (d==-1)
		exit(0);
	ans=max(ans, d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		ans=0;
		cin >> n;
		for (int i=0; i<9; ++i)
			qry(1<<i);
		cout << -1 << ' ' << ans << '\n';
		cout.flush();
	}
	return 0;
}