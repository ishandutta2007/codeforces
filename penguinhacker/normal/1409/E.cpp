#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
void test_case() {
	cin >> n >> k;
	vector<int> x(n);
	vector<int> save(n+1), suf(n+1);
	for (int i=0; i<n; ++i) cin >> x[i];
	for (int i=0, useless; i<n; ++i) cin >> useless;
	sort(x.begin(), x.end());
	for (int l=0, r=0; l<n; ++l) {
		while(r<n&&x[l]+k>=x[r]) ++r;
		save[l]=r-l;
	}
	for (int i=n-1; ~i; --i) suf[i]=max(suf[i+1], save[i]);
	int ans=0;
	for (int i=0; i<n; ++i) {
		ans=max(ans, save[i]+suf[i+save[i]]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) test_case();
	return 0;
}