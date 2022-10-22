#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, B=400;
int n, a[mxN], cnt[(mxN-1)*B+mxN], ans=1;
vector<int> rb;

void add(int x) {
	assert(0<=x&&x<(mxN-1)*B+mxN);
	++cnt[x];
	rb.push_back(x);
}

void solve(int o=0) {
	for (int i : rb) {
		ans=max(ans, cnt[i]+o);
		cnt[i]=0;
	}
	rb.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	rb.reserve(n);
	for (int rep=0; rep<2; ++rep) {
		for (int j=0; j<=B; ++j) {
			for (int i=0; i<n; ++i)
				add(a[i]-i*j+(n-1)*j);
			solve();
		}
		for (int i=1; i<n; ++i) {
			for (int j=1; j<mxN/B&&j<=i; ++j)
				if (a[i-j]<a[i]&&(a[i]-a[i-j])%j==0&&(a[i]-a[i-j])/j>B)
					add((a[i]-a[i-j])/j);
			solve(1);
		}
		for (int i=0; i<n; ++i)
			a[i]=mxN-1-a[i];
	}
	cout << n-ans;
	return 0;
}