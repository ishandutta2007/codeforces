#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, h, a[100001], first[100001], ans[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h;
	for (int i=0; i<=h; ++i)
		cin >> a[i];
	bool ok=1;
	for (int i=0; i<h; ++i)
		if (a[i]>1&&a[i+1]>1)
			ok=0;
	if (ok) {
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous\n";
	ans[0]=-1, n=1;
	for (int i=1; i<=h; ++i) {
		first[i]=n;
		for (int j=0; j<a[i]; ++j)
			ans[n++]=first[i-1];
	}
	for (int i=0; i<n; ++i)
		cout << ans[i]+1 << " ";
	for (int i=0; i<h; ++i)
		if (a[i]>1&&a[i+1]>1)
			ans[first[i+1]]=first[i]+1;
	cout << "\n";
	for (int i=0; i<n; ++i)
		cout << ans[i]+1 << " ";
	return 0;
}