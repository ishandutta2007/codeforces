#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	vector<bool> b(n);
	for (int i=1; i<n; ++i)
		b[i]=2*a[i]>a[i-1];
	int cur=0;
	for (int i=1; i<=k; ++i)
		cur+=b[i];
	int ans=(cur==k);
	//cout << ans << endl;
	for (int i=k+1; i<n; ++i) {
		cur+=b[i];
		cur-=b[i-k];
		ans+=(cur==k);
	}
	cout << ans << "\n";
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