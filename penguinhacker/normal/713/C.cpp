#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[3000];
ll ans;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i], a[i]-=i;
		pq.push(a[i]);
		if (pq.top()>a[i]) {
			ans+=pq.top()-a[i];
			pq.pop();
			pq.push(a[i]);
		}
	}
	cout << ans;
	return 0;
}