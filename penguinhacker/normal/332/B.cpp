#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll get_sum(const vector<ll> &sum, int l, int r) {
	return l==0 ? sum[r] : sum[r] -sum[l-1];
}

int n, k, a[200000];

int main() {
	int n, k;
	cin >> n >> k >> a[0];
	vector<ll> sum(n);
	sum[0] = a[0];
	for (int i=1; i<n; ++i) {
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}

	pair<int, int> ans={n-2*k, n-k};
	ll ans_sum = get_sum(sum, n-2*k, n-k-1) + get_sum(sum, n-k, n-1);
	pair<int, ll> suff_max = {n-k, get_sum(sum, n-k, n-1)};

	for (int i=n-2*k-1; i>=0; --i) {
		ll cur=get_sum(sum, i+k, i+2*k-1);
		if (cur>=suff_max.second)
			suff_max={i+k, cur};
		cur = get_sum(sum, i, i+k-1) + suff_max.second;
		if (cur>=ans_sum) {
			ans_sum = cur;
			ans = {i, suff_max.first};
		}
	}
	cout << ans.first+1 << ' ' << ans.second+1;
	return 0;
}