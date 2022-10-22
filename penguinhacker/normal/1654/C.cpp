#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	ll s=0;
	multiset<int> pieces;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		s+=a;
		pieces.insert(a);
	}
	priority_queue<ll> pq;
	pq.push(s);
	int cuts=0;
	while(cuts<n-1) {
		assert(pq.size());
		if (pq.top()<*pieces.rbegin()) {
			cout << "NO\n";
			return;
		}
		if (pq.top()==*pieces.rbegin()) {
			pq.pop();
			pieces.erase(--pieces.end());
		} else {
			ll x=pq.top();
			pq.pop();
			pq.push(x/2);
			pq.push((x+1)/2);
			++cuts;
		}
	}
	assert(pq.size()==pieces.size());
	while(pq.size()) {
		if (pq.top()!=*pieces.rbegin()) {
			cout << "NO\n";
			return;
		}
		pq.pop();
		pieces.erase(--pieces.end());
	}
	cout << "YES\n";
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