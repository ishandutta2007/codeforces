#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, q, a[mxN], cur=1, ans[mxN];
vector<int> b;
vector<ar<int, 2>> v[mxN];

int r(int x) {
	for (int i : b)
		x=min(x, x^i);
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<q; ++i) {
		int l, x;
		cin >> l >> x, --l;
		v[l].push_back({x, i});
	}
	for (int i=0; i<n; ++i) {
		if (!a[i]||!r(a[i]))
			cur=cur*2%M;
		else
			b.push_back(r(a[i]));
		for (ar<int, 2> c : v[i])
			ans[c[1]]=r(c[0])?0:cur;
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << "\n";
	return 0;
}