#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, k, a[mxN], cnt[mxN];
ll ans;
priority_queue<ar<ll, 2>> pq;

ll e(int i, int p) {
	ll f=a[i]/p;
	int m=a[i]%p;
	return (p-m)*f*f+m*(f+1)*(f+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		cnt[i]=1;
		ans+=e(i, 1);
		pq.push({e(i, 1)-e(i, 2), i});
	}
	while(n++<k) {
		ans-=pq.top()[0];
		int i=pq.top()[1];
		pq.pop();
		++cnt[i];
		pq.push({e(i, cnt[i])-e(i, cnt[i]+1), i});
	}
	cout << ans;
	return 0;
}