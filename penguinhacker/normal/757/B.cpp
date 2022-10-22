#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, cnt[mxN+1];
vector<int> f[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=2; i<=mxN; ++i)
		for (int j=i; j<=mxN; j+=i)
			f[j].push_back(i);
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		for (int j : f[x])
			++cnt[j];
	}
	cout << max(1, *max_element(cnt, cnt+mxN+1));
	return 0;
}