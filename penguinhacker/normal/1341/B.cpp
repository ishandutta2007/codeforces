#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[200000];
bool peak[200000];

void solve() {
	cin >> n >> k, k-=2;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	peak[0]=peak[n-1]=0;
	for (int i=1; i<n-1; ++i) {
		peak[i]=(a[i-1]<a[i]&&a[i]>a[i+1]);
	}
	int cnt=0;
	for (int i=1; i<=k; ++i)
		cnt+=peak[i];
	pair<int, int> ans={cnt, 1}; //cnt, ind
	for (int i=2; i+k-1<n-1; ++i) {
		cnt+=peak[i+k-1]-peak[i-1];
		if (cnt>ans.first)
			ans={cnt, i};
	}
	cout << ans.first+1 << ' ' << ans.second << '\n';
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