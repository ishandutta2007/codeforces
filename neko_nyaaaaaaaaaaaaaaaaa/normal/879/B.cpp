#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	
	k = min(k, 1000LL);
	int cnt = 0;
	int cur = q.front();
	q.pop();
	while (cnt < k) {
		if (cur > q.front()) {
			cnt++;
			q.push(q.front());
			q.pop();
		} else {
			q.push(cur);
			cur = q.front();
			q.pop();
			cnt = 1;
		}
	}
	
	cout << cur;
	
	return 0;
}