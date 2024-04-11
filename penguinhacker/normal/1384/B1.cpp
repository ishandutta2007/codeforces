#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, INF=1e9;
int n, k, l, a[mxN+2];

int get(int t) {
	return t<=k?t:2*k-t;
}

void solve() {
	cin >> n >> k >> l;
	a[0]=a[n+1]=-INF;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	if (*max_element(a+1, a+n+1)>l) {
		cout << "No\n";
		return;
	}
	int t=0;
	for (int i=0; i<n+1; ++i) {
		if (a[i]+k<=l)
			t=k;
		if (t>=k) { // decreasing
			if (a[i+1]+get(t+1)<=l)
				++t;
			else
				t=2*k-(l-a[i+1]);
		} else { // increasing so we must move forward
			if (a[i+1]+get(t+1)<=l)
				++t;
			else {
				cout << "No\n";
				return;
			}
		}
		t%=2*k;
	}
	cout << "Yes\n";
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