#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, x, ans[100000];
ar<int, 2> a[100000];

void solve() {
	cin >> n >> m >> x;
	for (int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i;
	sort(a, a+n);
	set<ar<int, 2>> s;
	for (int i=0; i<m; ++i)
		s.insert({0, i+1});
	for (int i=n-1; ~i; --i) {
		ar<int, 2> x=*s.begin();
		s.erase(x);
		x[0]+=a[i][0];
		ans[a[i][1]]=x[1];
		s.insert(x);
	}
	int mn=(*s.begin())[0], mx=(*s.rbegin())[0];
	if (mx-mn>x) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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