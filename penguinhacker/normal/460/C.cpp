#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD=1e9+7;

int n, m, w, a[100000], e[100000];

bool pos(int x) {
	memset(e, 0, sizeof(e));
	ll needed = 0;
	ll curr = 0;
	for (int i=0; i<n; ++i) {
		if (a[i]+curr<x) {
			ll add = x-(a[i]+curr);
			curr += add;
			needed += add;
			if (i+w-1<n)
				e[i+w-1] = add;
		}
		curr -= e[i];
	}
	return needed<=m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> w;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	ll lb=1;
	ll rb=1e9+1e6;
	while (lb<rb) {
		ll mid = (lb+rb+1)/2;
		if (pos(mid))
			lb = mid;
		else
			rb = mid-1;
	}
	cout << lb;
	return 0;
}