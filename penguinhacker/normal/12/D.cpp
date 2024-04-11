#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, ans;
ar<int, 3> a[mxN];
map<int, int> mp;

void ins(int a, int b) {
	auto it=mp.lower_bound(a);
	if (it!=mp.end()&&it->second>=b)
		return;
	it=mp.insert(it, {a, b}), it->second=b;
	while (it!=mp.begin()&&prev(it)->second<=b)
		mp.erase(prev(it));
}

ll qry(int x) {
	auto it=mp.upper_bound(x);
	return it==mp.end()?-1:it->second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<3; ++i)
		for (int j=0; j<n; ++j)
			cin >> a[j][i];
	sort(a, a+n, [](ar<int, 3> x, ar<int, 3> y) {return x[0]^y[0]?x[0]>y[0]:x[1]<y[1];});
	for (int i=0; i<n; ++i) {
		int x=a[i][1], y=a[i][2];
		if (qry(x)>y) {
			++ans;
			continue;
		}
		ins(x, y);
	}
	cout << ans;
	return 0;
}